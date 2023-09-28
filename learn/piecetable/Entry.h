#ifndef ENTRY_H
#define ENTRY_H
#include <string>

enum BufferType { B_ADD, B_ORIGINAL };

class Entry {
    public:
        Entry(int startIndex, int length, BufferType bufferType){
            this->startIndex = startIndex;
            this->length = length;
            this->bufferType = bufferType;
        };
        
        std::string toString() const {
            // tab characters are so beautiful
            // if I don't get a girl \t will do just fine
            // who am I kidding I code for fun

            // MISSIO's "Everybody Gets High":

            // \t was his friend, he didn't have another
            // g++ his vice, his real and only lover (yup)
            // wrote a hack or two, it never was a problem
            // got a segfault or two, they really made him blossom (yup)

            // there was that one funny time with left-pad when it got taken off of npm
            // and it was only 13 lines but a whole lotta of shit broke
            // witness \t
            return std::string(bufferType == B_ADD ? "ADD\t" : "ORIGINAL") + "\t"
            + std::to_string(startIndex) + "\t"
            + std::to_string(length);

            // the \t origin story is somewhat interesting
            // it goes back to typewriting
            // where tab would go to the next set position (around 4 spaces)
            // so if you have "a\t" it would go to "a   "
            // fun
        }

        bool operator==(const Entry& rhs){
            return rhs.startIndex == this->startIndex && rhs.length == this->length && rhs.bufferType == this->bufferType;
        }

        int startIndex;
        int length;
        BufferType bufferType;
};

#endif