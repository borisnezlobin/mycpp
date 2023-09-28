#include "Table.h"
#include "Entry.h"
#include <iostream>

int main(){
    PieceTable table ("./pt.txt");
    std::cout << table.toString() + "\n" << std::endl;
    table.append("\nsome text");
    std::cout << table.toString() << std::endl;
    std::cout << table.getChar(0) << std::endl; // T
    table.insert("add some text in the middle\n", 27);
    std::cout << table.toString() << std::endl;
    table.remove(6);
    // table.remove(28);
    std::cout << table.toString() << std::endl; // remove "a" from "add" (see L11)
    table.append("deleted text");
    std::cout << table.toString() << std::endl; // remove "i" from "is"
    std::cout << table.editsToString() << std::endl;
    table.undo();
    std::cout << table.editsToString() << std::endl;
    std::cout << table.toString() << std::endl;
    table.undo();
    // std::cout << table.editsToString() << std::endl;
    // std::cout << table.toString() << std::endl;
    // table.undo();
    std::cout << table.editsToString() << std::endl;
    std::cout << table.toString() << std::endl;
    table.save();
}