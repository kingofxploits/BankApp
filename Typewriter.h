#ifndef __TYPEWRITER__
#define __TYPEWRITER__

template<typename T>
void TypeWriter(T& message, int time) {
    std::string typeMessage = message;
    int count = 0;
    while (typeMessage[count] != NULL) {
        std::cout << typeMessage[count];
        Sleep(time);
        count++;
    } //end while loop
} //end TypeWriter()

#endif


