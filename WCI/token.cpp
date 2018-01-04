//
//  token.cpp
//  WCI
//
//  Created by cameron belt on 8/19/17.
//  Copyright © 2017 Cameron Belt. All rights reserved.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include "token.h"

void TWordToken::Get(TTextInBuffer &buffer){
    char ch = buffer.Char();
    char *ps = string;
    
    do{
        *ps++ = ch;
        ch = buffer.GetChar();
    }while((charCodeMap[ch] == ccLetter) || (charCodeMap[ch] == ccDigit));
    *ps = '\0';
    _strlwr_s(string);
    code = tcWord;
}

void TWordToken::Print(void) const{
    sprintf_s(list.text,"\t%-18s %-s",">> word:",string);
    list.PutLine();
}

void TNumberToken::Get(TTextInBuffer &buffer){
    const int maxDigitCount = 4;
    
    char ch = buffer.Char();
    char *ps = string;
    int digitCount = 0;
    int countErrorFlag = false;
    
    value.integer = 0;
    do{
        *ps++ = ch;
        if(++digitCount <= maxDigitCount){
            value.integer = 10*value.integer + (ch-'0');
        }
        else countErrorFlag = true;
        
        ch = buffer.GetChar();
    }while(charCodeMap[ch] == ccDigit);
    *ps = '\0';
    code = countErrorFlag ? tcError : tcNumber;
}

void TNumberToken::Print(void) const{
    sprintf_s(list.text, "\t%-18s =%d",">> number:",value.integer);
    list.PutLine();
}

void TSpecialToken::Get(TTextInBuffer &buffer){
    char ch = buffer.Char();
    char *ps = string;
    
    *ps++ = ch;
    *ps = '\0';
    buffer.GetChar();
    
    code = (ch == '.') ? tcPeriod : tcError;
}

void TSpecialToken::Print(void)const{
    sprintf_s(list.text, "\t%-18s %-s",">> special:",string);
    list.PutLine();
}

void TErrorToken::Get(TTextInBuffer &buffer){
    string[0] = buffer.Char();
    string[1] = '\0';
    buffer.GetChar();
}