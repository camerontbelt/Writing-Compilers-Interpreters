//
//  parser.cpp
//  WCI
//
//  Created by cameron belt on 1/4/18.
//  Copyright © 2018 Cameron Belt. All rights reserved.
//
#include <stdio.h>
#include "common.h"
#include "buffer.h"
#include "error.h"
#include "parser.h"

void TParser::Parse(void){
    do{
        GetToken();
        if(token != tcError){
            pToken->Print();
        }
        else{
            sprintf(list.text, "\t%-18s %-s",">> *** Error ***",pToken->String());
            list.PutLine();
            ++errorCount;
        }
    }while(token != tcEndOfFile);
    
    list.PutLine();
    sprintf(list.text, "%20d source lines.", currentLineNumber);
    list.PutLine();
    sprintf(list.text, "%20d syntax errors.", errorCount);
    list.PutLine();
}
