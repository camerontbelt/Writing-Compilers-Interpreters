//
//  buffer.h
//  WCI
//
//  Created by cameron belt on 8/9/17.
//  Copyright © 2017 Cameron Belt. All rights reserved.
//

#ifndef buffer_h
#define buffer_h

#include "stdafx.h"
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include "misc.h"
#include "error.h"

using namespace std;
extern char eofChar;
extern int inputPosition;
extern int listFlag;
extern int level;

const int maxInputBufferSize = 256;

//Super class
class TTextInBuffer {
protected:
    fstream file;
    char *const pFileName;
    char text[maxInputBufferSize];
    char *pChar;
    
    virtual char GetLine(void) = 0;
    
public:
    TTextInBuffer(const char *pInputFileName, TAbortCode ac);
    
    virtual ~TTextInBuffer(void){
        file.close();
        delete pFileName;
    }
    
    char Char(void) const {return *pChar;};
    char GetChar(void);
    char PutBackChar(void);
};


//Subclass of TextInBuffer
class TSourceBuffer : public TTextInBuffer{
    virtual char GetLine(void);
    
public:
    TSourceBuffer(const char *pSourceFileName);
};

class TTextOutBuffer {
public:
    char text[maxInputBufferSize + 16];
    virtual void PutLine(void) = 0;
    void PutLine(const char *pText){
        strcpy_s(text, pText);
        PutLine();
    }
};

class TListBuffer : public TTextOutBuffer {
    char *pSourceFileName;
    char date[26];
    int pageNumber;
    int lineCount;
    
    void PrintPageHeader(void);
    
public:
    virtual ~TListBuffer(void){ delete pSourceFileName; }
    
    void Initialize(const char *fileName);
    
    virtual void PutLine(void);
    
    void PutLine(const char *pText){
        TTextOutBuffer::PutLine(pText);
    }
    
    void PutLine(const char *pText, int lineNumber, int nestingLevel){
        sprintf_s(text, "%4d %d: %s",lineNumber, nestingLevel, pText);
        PutLine();
    }
};

extern TListBuffer list;

#endif /* buffer_h */
