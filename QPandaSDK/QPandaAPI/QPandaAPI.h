/*****************************************************************************************************************
Copyright:
Author:Dou Menghan
Date:2018-01-19
Description: QParserSDK
*****************************************************************************************************************/
#ifndef  _QPARSER_SDK_API_H
#define  _QPARSER_SDK_API_H
#include <iostream>
#include "../QRunesParser/QRunesParserAPI.h"
#include "../QuantumInstructionHandle/QuantumGateParameter.h"
#include "../QuantumInstructionHandle/QuantumInstructionHandleAPI.h"
#include "../QuantumInstructionHandle/QError.h"
#ifdef _WIN32
#define DLL_EXPORTS
#ifdef DLL_EXPORTS
#define DLL_EXPORTS_API __declspec(dllexport)
#else
#define DLL_EXPORTS_API __declspec(dllimport)
#endif
#elif __linux__
#define DLL_EXPORTS_API  
#endif
namespace QPanda 
{
#define STRING     std::string
#define CPU        1
#define GPU        2
#define MEASURE    1
#define PMEASURE   2
#define PAIR       pair<string,double>

class  QPandaAPI 
{
public:
    STRING                        msFileName;                           /* file name                            */
    STRING                        msResult;
    STRING                        msState;
    QPandaAPI();
    ~QPandaAPI();
    /*************************************************************************************************************
    Name:        loadFile
    Description: load quantum program
    Argin:       sFilePath  quantum program file path
    Argout:      Qnum       quantum bit num
    return:      qerror
    *************************************************************************************************************/
    QError loadFile(const string &sFilePath,int &Qnum);

    /*************************************************************************************************************
    Name:        setComputeUnit
    Description: set compute unit,you have two options:CPU or GPU.you can not choose again when you have 
                 already selected a compute unit
    Argin:       iComputeUnit  the type of compute unit
    Argout:      None
    return:      qerror
    *************************************************************************************************************/
    QError setComputeUnit(int iComputeUnit);

    /*************************************************************************************************************
    Name:        run
    Description: run quantum program
    Argin:       iRepeat    quantum program repeat
    Argout:      None
    return:      qerror
    *************************************************************************************************************/
    QError run(int iRepeat);

    /*************************************************************************************************************
    Name:        getResult
    Description: get quantum program result
    Argin:       None
    return:      qerror
    *************************************************************************************************************/
    QError getResult();

    /*************************************************************************************************************
    Name:        getQuantumState
    Description: get quantum program qstate
    Argin:       None
    return:      qerror
    *************************************************************************************************************/
    QError getQuantumState();

 private:
    map<string,double>            mQResultMap;                          /* quantum program result map           */
    QList                         mQList;
    bool                          mbIsRead = false;                     /* is read quantum program file         */
    QuantumGateParam              mQGatesParam;
    QuantumInstructionHandleAPI   mQHandle;
    int                           miComputeType;                        /* quantum program file is read         */
    int                           miMeasureType;                        /* quantum program measure type         */
    bool                          mbIsRun = false;                      /* quantum program is run               */
    /*************************************************************************************************************
    Name:        statisticalResults
    Description: statistical results
    Argin:       None
    Argout:      None
    return:      None
    *************************************************************************************************************/
    void countState();

    /*************************************************************************************************************
    Name:        integerToBinary
    Description: integer to binary
    Argin:       number     src number
                 iRetLen    ssRet len
    Argout:      ssRet      binary result
    return:      true or false
    *************************************************************************************************************/
    bool integerToBinary(int number,stringstream &ssRet, int iRetLen);
};
}
#endif
