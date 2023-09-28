#ifndef PT_TABLE_H
#define PT_TABLE_H

#include "Entry.h"
#include "../linkedlist/LinkedList.h"
// ^ bad if you change your directory structure
// guess I just won't

#include <string>
#include <fstream>
#include <stack>
#include <vector>

struct entry_value {
    Entry* entry;
    int leftover;
    Node<Entry*>* entryNode;
    int nodeIndex;
};

enum EditType { E_ADD, E_REMOVE };

template <class T>
struct edit {
    edit(Node<T>* node, int i, int l, EditType e) : index {i}, length {l}, removeAtStart {false}, editType {e} {
        this->node = node;
    }
    edit(Node<T>* node, int i, int l, EditType e, bool r) : index {i}, length {l}, editType {e} {
        this->node = node;
        if(e == E_REMOVE) this->removeAtStart = r;
    }

    std::string toString(){
        std::string opType = ""; // idk why I have to do this
        if(this->editType == E_ADD) opType = "ADD";
        else opType = "REMOVE";
        return opType + " at " + std::to_string(index) + " with length " + std::to_string(length); 
    }

    Node<T>* node;
    EditType editType;
    int index; // index of Node node
    int length; // how many nodes change
    bool removeAtStart; // only for EditType.E_REMOVE
};

// ngl piece tables are kinda amazing (when implemented correctly, ihncl how to do shit right)
// I mean sure so are bsts
// and ropes
// and linked lists
// and resizing arrays
// but piece tables are pretty cool
class PieceTable {
    public:
        PieceTable(std::string originalFileName){
            this->originalFile = originalFileName;
            std::ifstream original(originalFileName);
            std::string contents;
            while(original && original.is_open()){
                char c = original.get();
                contents += c;
            }
            Entry* start = new Entry(0, contents.length() - 1, B_ORIGINAL);
            this->table.push(start);
        }

        std::string originalFile; // technically I shouldn't store it as a string but watch me care
        std::string addBuffer;
        int addFileLength = 0;

        char getChar(int index);
        void append(std::string entry);
        void insert(std::string entry, int index);
        void remove(int index);
        bool save();
        std::string toString();
        std::string editsToString(){
            std::string s = "";
            s += std::to_string(history.size()) + " edit" + (history.size() == 1 ? ": " : "s: ");
            for(int i = history.size() - 1; i >= 0; i--){
                s += history.at(i)->toString();
                if(i != 0) s += ", ";
            }
            return s;
        }
        void undo(); // eek

    private:
        LinkedList<Entry*> table;
        entry_value getEntry(int index);

        // I *should* use a stack, but used a vector so that I could print it
        // I'm just like that
        // making bad technical decisions is my talent

        // the fall out boy lyrics screwed with my autocomplete
        // we'll go down in historyyyyyyyyy, remember me for centurieeeeees, we'll go down in historyyyyyy
        std::vector<edit<Entry*>*> history;
};

#endif