//
//  scanner.cpp
//  WCI
//
//  Created by cameron belt on 8/19/17.
//  Copyright © 2017 Cameron Belt. All rights reserved.
//

#include "scanner.h"
TCharCode charCodeMap[128];

TTextScanner::TTextScanner(TTextInBuffer *pBuffer):pTextInBuffer(pBuffer){
    int i;
    
    for(i = 0; i <= 127; ++i)
        charCodeMap[i] = ccError;
    for(i = 'a'; i <= 'z'; ++i)
        charCodeMap[i] = ccLetter;
    for(i = 'A'; i <= 'Z'; ++i)
        charCodeMap[i] = ccLetter;
    for(i = '0'; i <= '9'; ++i)
        charCodeMap[i] = ccDigit;
    charCodeMap['+'] = charCodeMap['-'] = ccSpecial;
    charCodeMap['*'] = charCodeMap['/'] = ccSpecial;
    charCodeMap['='] = charCodeMap['^'] = ccSpecial;
    charCodeMap['.'] = charCodeMap[','] = ccSpecial;
    charCodeMap['<'] = charCodeMap['>'] = ccSpecial;
    charCodeMap['('] = charCodeMap[')'] = ccSpecial;
    charCodeMap['['] = charCodeMap[']'] = ccSpecial;
    charCodeMap['{'] = charCodeMap['}'] = ccSpecial;
    charCodeMap[':'] = charCodeMap[';'] = ccSpecial;
    charCodeMap[' '] = charCodeMap['\t'] = ccWhiteSpace;
    charCodeMap['\n'] = charCodeMap['\0'] = ccWhiteSpace;
    charCodeMap['\''] = ccQuote;
    charCodeMap[eofChar] = ccEndOfFile;
}

void TTextScanner::SkipWhiteSpace(void){
    char ch = pTextInBuffer->Char();
    
    while (charCodeMap[ch] == ccWhiteSpace) {
        ch = pTextInBuffer->GetChar();
    };
}

TToken *TTextScanner::Get(void){
    TToken *pToken;
    
    SkipWhiteSpace();
    
    switch (charCodeMap[pTextInBuffer->Char()]) {
        case ccLetter:
            pToken = &wordToken;
            break;
        case ccDigit:
            pToken = &numberToken;
            break;
        case ccQuote:
            pToken = &stringToken;
            break;
        case ccSpecial:
            pToken = &specialToken;
            break;
        case ccEndOfFile:
            pToken = &eofToken;
            break;
        default:
            pToken = &errorToken;
            break;
    }
    pToken->Get(*pTextInBuffer);
    return pToken;
}
