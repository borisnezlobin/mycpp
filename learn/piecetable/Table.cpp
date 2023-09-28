#include "Entry.h"
#include "Table.h"
#include "../linkedlist/LinkedList.h"
#include "../linkedlist/Node.h"
#include <fstream>
#include <string>
#include <iostream>

entry_value PieceTable::getEntry(int index){
    Node<Entry*>* current = this->table.get(0);
    int currentCount = 0;
    int i = 0;

    while(currentCount + current->value->length < index){
        currentCount += current->value->length;
        current = current->next;
        i++;
    }

    Entry* entry = current->value;
    entry_value ret;

    // because wtf is a constructor anyways
    ret.entry = entry;
    ret.leftover = index - currentCount;
    ret.entryNode = current;
    ret.nodeIndex = i;
    return ret;
}

char PieceTable::getChar(int index){
    entry_value ev = getEntry(index);
    Entry* entry = ev.entry;
    std::string item;
    if(entry->bufferType == B_ADD){
        item = this->addBuffer.substr(entry->startIndex, entry->length);
    }else{
        int i = 0;
        std::ifstream stream(this->originalFile);
        while(i < entry->startIndex && stream && stream.is_open()){
            stream.get();
            i++;
        }
        // TODO: handle errors
        for(i = 0; i < entry->length; i++){
            item += stream.get();
        }
        // item = this->originalFile.substr(entry->startIndex, entry->length);
    }
    return item.at(ev.leftover);
}

void PieceTable::append(std::string entry){
    addBuffer += entry;

    Entry* newEntry = new Entry(this->addFileLength, entry.length(), B_ADD);
    Node<Entry*>* newNode = this->table.push(newEntry);

    edit<Entry*>* thisEdit = new edit(newNode, this->table.getSize(), 1, E_ADD);
    this->history.push_back(thisEdit);
    this->addFileLength += entry.length();
}

void PieceTable::insert(std::string entry, int index){
    this->addBuffer += entry;

    if(index == 0){
        Entry* newEntry = new Entry(this->addFileLength, entry.length(), B_ADD);
        Node<Entry*>* newNode = this->table.add(newEntry, 0);
        this->addFileLength += entry.length();
        edit<Entry*>* thisEdit = new edit(newNode, 0, 1, E_ADD);
        this->history.push_back(thisEdit);
        return;
    }

    entry_value block = getEntry(index);
    Entry* og = block.entry;
    int temp = og->length;
    og->length = block.leftover;
    Entry* newEntry = new Entry(this->addFileLength, entry.length(), B_ADD);
    Entry* close = new Entry(og->startIndex + og->length, temp - og->length, B_ORIGINAL);

    // add newEntry and close to this->table
    Node<Entry*>* addNode = new Node(newEntry);
    Node<Entry*>* closeNode = new Node(close);
    this->table.add(addNode, block.entryNode);
    this->table.add(closeNode, addNode);

    edit<Entry*>* thisEdit = new edit(block.entryNode, block.nodeIndex, 3, E_ADD);
    this->history.push_back(thisEdit);
    this->addFileLength += entry.length();
}

void PieceTable::remove(int index){
    entry_value piece = getEntry(index);

    // idk how to handle off-by-one errors so I just do shit like this
    if(piece.leftover <= 1){
        piece.entry->startIndex++;
        piece.entry->length--;
        edit<Entry*>* thisEdit = new edit(piece.entryNode, piece.nodeIndex, 1, E_REMOVE, true);
        this->history.push_back(thisEdit);
        return;
    }

    if(piece.leftover == piece.entry->length - 1){
        piece.entry->length--;
        edit<Entry*>* thisEdit = new edit(piece.entryNode, piece.nodeIndex, 1, E_REMOVE, false);
        this->history.push_back(thisEdit);
        return;
    }

    Entry* newPiece = new Entry(piece.entry->startIndex + piece.leftover, piece.entry->length - piece.leftover, piece.entry->bufferType);
    Node<Entry*>* newNode = new Node(newPiece);
    this->table.add(newNode, piece.entryNode);
    piece.entry->length = piece.leftover - 1;

    edit<Entry*>* thisEdit = new edit(piece.entryNode, piece.nodeIndex, 2, E_REMOVE);
    this->history.push_back(thisEdit);
}

void PieceTable::undo(){
    edit<Entry*>* lastEdit = this->history.at(this->history.size() - 1);

    if(lastEdit->editType == E_ADD){
        // if length is 1, we can just remove the edit
        if(lastEdit->length == 1){
            this->table.remove(lastEdit->index - 1); // I really don't know why I subtract 1
            this->history.pop_back();
            return;
        }else if(lastEdit->length == 3){
            // merge table[index] and table[index + 2], delete table[index + 1] + table[index + 2]
            // let's just assume that table[index + 1] and table[index + 2] exist
            Node<Entry*>* start = lastEdit->node;
            Node<Entry*>* temp = start->next->next;
            start->value->length = start->value->length + temp->value->length;

            // remove table[index + 1], table[index + 2]
            this->table.remove(temp->value);
            this->table.remove(start->next->value);

            // lmao I spent time debugging a segfault and it turns out that I just forgot this
            this->history.pop_back();
        }
    }else if(lastEdit->editType == E_REMOVE){
        if(lastEdit->length == 1){
            lastEdit->node->value->length++;
            if(lastEdit->removeAtStart){
                lastEdit->node->value->startIndex--;
            }
            this->history.pop_back();
        }else if(lastEdit->length == 2){
            Node<Entry*>* temp = lastEdit->node->next;
            lastEdit->node->value->length = lastEdit->node->value->length + 1 + temp->value->length;
            this->table.remove(temp->value);
            this->history.pop_back();
        }
    }
}

bool PieceTable::save(){
    std::string original;
    std::fstream f(this->originalFile);
    while(f.is_open() && f){
        original += f.get();
    }
    f.close();

    // wtf `input/output stream::append` = `ios::app`??
    // ^ i hate apple 1984
    f.open(this->originalFile, std::ofstream::out | std::ofstream::trunc);
    f.close();

    std::string total;
    Node<Entry*>* current = this->table.get(0);
    for(int i = 0; i < this->table.getSize(); i++){
        Entry* e = current->value;
        if(e->bufferType == B_ADD){
            total += this->addBuffer.substr(e->startIndex, e->length);
        }else{
            total += original.substr(e->startIndex, e->length);
        }
        current = current->next;
    }

    f.open(this->originalFile);
    f << total;
    return true;
}

std::string PieceTable::toString(){
    return "Piece Table with " +
        std::to_string(this->table.getSize()) +
        " element" + (this->table.getSize() == 1 ? "" : "s") + ":\n" +
        this->table.toString()
    ;
}