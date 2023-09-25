//
// Created by Uddhav on 25-09-2023.
//

#ifndef RUBIKS_CORNERPATTERNDATABASE_H
#define RUBIKS_CORNERPATTERNDATABASE_H

#include "../Model/GenericRubiksCube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"
using namespace std;

class CornerPatternDatabase : public PatternDatabase {

    typedef RubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const RubiksCube& cube) const;

};

#endif //RUBIKS_CORNERPATTERNDATABASE_H
