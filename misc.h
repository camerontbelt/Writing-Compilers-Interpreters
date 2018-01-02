//
//  misc.h
//  WCI
//
//  Created by cameron belt on 8/9/17.
//  Copyright © 2017 Cameron Belt. All rights reserved.
//

#ifndef misc_h
#define misc_h

//const int false = 0;
//const int true = 1;

enum TCharCode{
    ccLetter
    ,ccDigit
    ,ccSpecial
    ,ccQuote
    ,ccWhiteSpace
    ,ccEndOfFile
    ,ccError
    ,
};

enum TTokenCode{
    tcDummy
    ,tcWord
    ,tcNumber
    ,tcPeriod
    ,tcEndOfFile
    ,tcError
    ,
};

enum TDataType{
    tyDummy
    ,tyInteger
    ,tyReal
    ,tyCharacter
    ,tyString
    ,
};

union TDataValue{
    int integer;
    float real;
    char character;
    char *pString;
};

#endif /* misc_h */
