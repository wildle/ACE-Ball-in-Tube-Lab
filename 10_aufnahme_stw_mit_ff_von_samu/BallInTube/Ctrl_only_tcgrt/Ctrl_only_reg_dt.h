/*
 * Ctrl_only_reg_dt.h
 *
 */

{
  DataTypeTransInfo *dtInfo;
  uint_T *DataTypeSizes;
  const char_T **DataTypeNames;
  DataTypeTransition *BTransitions;
  DataTypeTransitionTable *BTransTable;
  B_Ctrl_only_T *Ctrl_only_B = (B_Ctrl_only_T *) Ctrl_only_M->blockIO;
  DW_Ctrl_only_T *Ctrl_only_DW = (DW_Ctrl_only_T *) Ctrl_only_M->dwork;
  DataTypeTransition *PTransitions;
  DataTypeTransitionTable *PTransTable;

  /* structure to hold model's data type transition information */
  dtInfo = (DataTypeTransInfo *) malloc(sizeof(DataTypeTransInfo));
  rt_VALIDATE_MEMORY(Ctrl_only_M,dtInfo);
  (void) std::memset(static_cast<void *>(dtInfo), 0,
                     sizeof(DataTypeTransInfo));
  dtInfo->numDataTypes = 19;
  Ctrl_only_M->SpecialInfo.mappingInfo = (dtInfo);

  /* data type sizes */
  DataTypeSizes = (uint_T *) malloc(19 * sizeof(uint_T));
  rt_VALIDATE_MEMORY(Ctrl_only_M,DataTypeSizes);
  dtInfo->dataTypeSizes = DataTypeSizes;
  DataTypeSizes[0] = sizeof(real_T);
  DataTypeSizes[1] = sizeof(real32_T);
  DataTypeSizes[2] = sizeof(int8_T);
  DataTypeSizes[3] = sizeof(uint8_T);
  DataTypeSizes[4] = sizeof(int16_T);
  DataTypeSizes[5] = sizeof(uint16_T);
  DataTypeSizes[6] = sizeof(int32_T);
  DataTypeSizes[7] = sizeof(uint32_T);
  DataTypeSizes[8] = sizeof(boolean_T);
  DataTypeSizes[9] = sizeof(fcn_call_T);
  DataTypeSizes[10] = sizeof(int_T);
  DataTypeSizes[11] = sizeof(pointer_T);
  DataTypeSizes[12] = sizeof(action_T);
  DataTypeSizes[13] = 2*sizeof(uint32_T);
  DataTypeSizes[14] = sizeof(int32_T);
  DataTypeSizes[15] = sizeof(uint_T);
  DataTypeSizes[16] = sizeof(char_T);
  DataTypeSizes[17] = sizeof(uchar_T);
  DataTypeSizes[18] = sizeof(time_T);

  /* data type names */
  DataTypeNames = (const char_T **) malloc(19 * sizeof(char_T *));
  rt_VALIDATE_MEMORY(Ctrl_only_M,DataTypeNames);
  dtInfo->dataTypeNames = DataTypeNames;
  DataTypeNames[0] = "real_T";
  DataTypeNames[1] = "real32_T";
  DataTypeNames[2] = "int8_T";
  DataTypeNames[3] = "uint8_T";
  DataTypeNames[4] = "int16_T";
  DataTypeNames[5] = "uint16_T";
  DataTypeNames[6] = "int32_T";
  DataTypeNames[7] = "uint32_T";
  DataTypeNames[8] = "boolean_T";
  DataTypeNames[9] = "fcn_call_T";
  DataTypeNames[10] = "int_T";
  DataTypeNames[11] = "pointer_T";
  DataTypeNames[12] = "action_T";
  DataTypeNames[13] = "timer_uint32_pair_T";
  DataTypeNames[14] = "physical_connection";
  DataTypeNames[15] = "uint_T";
  DataTypeNames[16] = "char_T";
  DataTypeNames[17] = "uchar_T";
  DataTypeNames[18] = "time_T";

  /* data type transitions for block I/O structure */
  BTransitions = (DataTypeTransition *)
    malloc(6 * sizeof(DataTypeTransition));
  rt_VALIDATE_MEMORY(Ctrl_only_M,BTransitions);
  BTransitions[0].baseAddr = (char_T *)(&Ctrl_only_B->Delay);
  BTransitions[0].dataType = 0;
  BTransitions[0].isComplex = 0;
  BTransitions[0].nEls = 23;
  BTransitions[1].baseAddr = (char_T *)(&Ctrl_only_B->DataTypeConversion2);
  BTransitions[1].dataType = 5;
  BTransitions[1].isComplex = 0;
  BTransitions[1].nEls = 1;
  BTransitions[2].baseAddr = (char_T *)(&Ctrl_only_DW->Integrator_DSTATE);
  BTransitions[2].dataType = 0;
  BTransitions[2].isComplex = 0;
  BTransitions[2].nEls = 2;
  BTransitions[3].baseAddr = (char_T *)(&Ctrl_only_DW->height_PWORK.LoggedData[0]);
  BTransitions[3].dataType = 11;
  BTransitions[3].isComplex = 0;
  BTransitions[3].nEls = 8;
  BTransitions[4].baseAddr = (char_T *)(&Ctrl_only_DW->sfEvent);
  BTransitions[4].dataType = 6;
  BTransitions[4].isComplex = 0;
  BTransitions[4].nEls = 1;
  BTransitions[5].baseAddr = (char_T *)(&Ctrl_only_DW->doneDoubleBufferReInit);
  BTransitions[5].dataType = 8;
  BTransitions[5].isComplex = 0;
  BTransitions[5].nEls = 1;

  /* data type transition table for block I/O structure */
  BTransTable = (DataTypeTransitionTable *)
    malloc(sizeof(DataTypeTransitionTable));
  rt_VALIDATE_MEMORY(Ctrl_only_M,BTransTable);
  BTransTable->numTransitions = 6U;
  BTransTable->transitions = BTransitions;

  /* attach block I/O transition table */
  dtInfo->BTransTable = BTransTable;

  /* data type transitions for parameters structure */
  PTransitions = (DataTypeTransition *)
    malloc(2 * sizeof(DataTypeTransition));
  rt_VALIDATE_MEMORY(Ctrl_only_M,PTransitions);
  PTransitions[0].baseAddr = (char_T *)(&Ctrl_only_P.PIDController_D);
  PTransitions[0].dataType = 0;
  PTransitions[0].isComplex = 0;
  PTransitions[0].nEls = 21;
  PTransitions[1].baseAddr = (char_T *)(&Ctrl_only_P.PIDvsFF_CurrentSetting);
  PTransitions[1].dataType = 3;
  PTransitions[1].isComplex = 0;
  PTransitions[1].nEls = 4;

  /* data type transition table for parameters structure */
  PTransTable = (DataTypeTransitionTable *)
    malloc(sizeof(DataTypeTransitionTable));
  rt_VALIDATE_MEMORY(Ctrl_only_M,PTransTable);
  PTransTable->numTransitions = 2U;
  PTransTable->transitions = PTransitions;

  /* attach parameters transition table */
  dtInfo->PTransTable = PTransTable;
}

/* [EOF] Ctrl_only_reg_dt.h */
