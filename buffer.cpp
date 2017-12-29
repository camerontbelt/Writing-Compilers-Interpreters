//
//  buffer.cpp
//  WCI
//
//  Created by cameron belt on 8/9/17.
//  Copyright © 2017 Cameron Belt. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include "common.h"
#include "buffer.h"

char eofChar = 0x7f;
int inputPostion;

int listFlag = true;

//constructor
TTextInBuffer::TTextInBuffer(const char *pInputFileName, TAbortCode ac)
:pFileName(new char[strlen(pInputFileName)]){
    strcpy(pFileName, pInputFileName);
    
    file.open(pFileName, ios::in);
    if (!file.good())
        AbortTranslation(ac);
}

//get next character
char TTextInBuffer::GetChar(void){
    const int tabSize = 8;
    char ch;
    
    if(*pChar == eofChar){
        return eofChar;
    }
    else if(*pChar == '\0'){
        ch = GetLine();
    }
    else{
        ++pChar;
        ++inputPostion;
        ch = *pChar;
    }
    
    if (ch == '\t'){
        inputPostion += tabSize - inputPostion%tabSize;
    }
    return ch;
}

char TTextInBuffer::PutBackChar(void){
    --pChar;
    --inputPostion;
    return *pChar;
}

TSourceBuffer::TSourceBuffer(const char *pSourceFileName)
: TTextInBuffer(pSourceFileName, abortSourceFileOpenFailed){
    if(listFlag){
        list.Initialize(pSourceFileName);
    }
    GetLine();
}

char TSourceBuffer::GetLine(void){
    extern int lineNumber, currentNestingLevel;
    
    if(file.eof()){
        pChar = &eofChar;
    }
    else{
        file.getline(text,maxInputBufferSize);
        pChar = text;
        if(listFlag)
            list.PutLine(text, ++currentLineNumber, currentNestingLevel);
    }
    inputPostion = 0;
    return *pChar;
}

const int maxPrintLineLength = 80;
const int maxLinesPerPage = 50;

TListBuffer list;

void TListBuffer::PrintPageHeader(void){
    const char formFeedChar = '\f';
    cout << formFeedChar << "Page " << ++pageNumber << "  " << pSourceFileName <<
    "   " << date << endl << endl;
    
    lineCount = 0;
}

void TListBuffer::Initialize(const char *pFileName){
    text[0] = '\0';
    pageNumber = 0;
    
    pSourceFileName = new char[strlen(pFileName) + 1];
    strcpy(pSourceFileName, pFileName);
    
    time_t timer;
    time(&timer);strcpy(date, asctime(localtime(&timer)));
    date[strlen(date) - 1] = '\0';
    PrintPageHeader();
}

void TListBuffer::PutLine(void){
    if(listFlag && (lineCount == maxLinesPerPage)) PrintPageHeader();
    
    text[maxPrintLineLength] = '\0';
    
    cout << text << endl;
    text[0] = '\0';
    ++lineCount;
}






