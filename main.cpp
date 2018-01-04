//
//  main.cpp
//  WCI
//
//  Created by cameron belt on 8/9/17.
//  Copyright © 2017 Cameron Belt. All rights reserved.
//

#include <iostream>
#include "buffer.h"
#include "error.h"
#include "parser.h"

using namespace std;

int main(int argc, const char * argv[]) {
        
    if(argc != 2){
        cerr << "Usage: list <source file>" << endl;
        AbortTranslation(abortInvalidCommandLineArgs);
    }
    TParser parser(new TSourceBuffer(argv[1]));
    parser.Parse();
    
//    do{
//        ch = source.GetChar();
//    }while(ch != eofChar);
    return 0;
}
