//
//  parser.h
//  WCI
//
//  Created by cameron belt on 1/4/18.
//  Copyright © 2018 Cameron Belt. All rights reserved.
//

#ifndef parser_h
#define parser_h

#include <stdio.h>
#include "misc.h"
#include "buffer.h"
#include "token.h"
#include "scanner.h"

class TParser {
    TTextScanner *const pScanner;
    TToken *pToken;
    TTokenCode token;
    
    void GetToken(void){
        pToken = pScanner->Get();
        token = pToken->Code();
    }
    
public:
    TParser(TTextInBuffer *pBuffer) : pScanner(new TTextScanner(pBuffer)){}
    ~TParser(void){
        delete pScanner;
    }
    void Parse(void);
};

#endif /* parser_hpp */
