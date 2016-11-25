/**********************************************************************
 *
 * sstDxf02Lib - sst dxf library
 * Hosted on github
 *
 * Copyright (C) 2016 Uli Rehr
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file gpl-2.0.txt included in the
 * packaging of this file.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * This copyright notice MUST APPEAR in all copies of the script!
 *
**********************************************************************/
// sstCsv2Dxf.h   11.03.16  Re.   11.03.16  Re.
//
// Datastructures and Prototypes for system "sstDxf01Lib"
//

#ifndef SST_CSV2DXF_HEADER
#define SST_CSV2DXF_HEADER

// Foreward definition
class sstDxf01DatabaseCls;
class sstDxf02FncMainCls;

//==============================================================================
class sstCsv2DxfCls : public sstMisc01PrtFilCls
{
  public:   // Public functions
     sstCsv2DxfCls();  // Constructor
   //  ~sstDxf2CsvCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory  <BR>
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void testReading(char* file);
     void usage();
     // sstMisc01PrtFilCls oPrt; /**< output protocol file */
// ----------------------------------------------------------------------------
  private:  // Private functions
};
//-----------------------------------------------------------------------------
////==============================================================================
///**
//* @brief dxf main record for storing in record memory
//*
//* Changed: 08.07.15  Re.
//*
//* @ingroup sstDxf02Lib
//*
//* @author Re.
//*
//* @date 08.07.15
//*/
//// ----------------------------------------------------------------------------
//class sstDxf02TypMainCls
//{
//  public:   // Public functions
//     sstDxf02TypMainCls();  // Constructor
//    //~sstTestBaseCls();  // Destructor
//     //==============================================================================
//     /**
//     * @brief // Shortstory <BR>
//     * iStat = oTestBase.Func_1(iKey);
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//    // int Func_1(int iKey);
//// ----------------------------------------------------------------------------

//     //  number; Section; numSect;  Type; numType;
//     //       1;       B;    567;    Arc;     234;
//     dREC04RECNUMTYP getMainID() const;
//     void setMainID(const dREC04RECNUMTYP &value);

//     std::string getSectString() const;
//     void setSectString(const std::string &oSectString);

//     dREC04RECNUMTYP getLayBlockID() const;
//     void setLayBlockID(const dREC04RECNUMTYP &value);

//     RS2::EntityType getEntityType() const;
//     void setEntityType(const RS2::EntityType &value);

//     dREC04RECNUMTYP getTypeID() const;
//     void setTypeID(const dREC04RECNUMTYP &value);

//private:  // Private functions
//  dREC04RECNUMTYP   dMainID;      /**< Record number in this main file */
//  char              cSectionType[2];  /**< L or B */
//  dREC04RECNUMTYP   dLayBlockID;   /**< Record number in Layer or block file */
////   char cElementType[16];         /**< ARC. CIRCE, LINE, VERTEX and so on ... */
//  RS2::EntityType   eEntityType;     /**< ARC. CIRCE, LINE, VERTEX and so on ... */
//  dREC04RECNUMTYP   dTypeID;          /**< Record number in type file */

//};
////==============================================================================
///**
//* @brief Definition Class sstTestBaseInternCls
//*
//* template for sst base class <BR>
//*
//* Changed: 08.07.15  Re.
//*
//* @ingroup sstTemplateIntLib
//*
//* @author Re.
//*
//* @date 08.07.15
//*/
//// ----------------------------------------------------------------------------
//class sstDxf02FncMainCls : public sstDxf02FncBaseCls
//{
//  public:   // Public functions
//     sstDxf02FncMainCls();  // Constructor
//    //~sstTestBaseCls();  // Destructor
//     //==============================================================================
//     /**
//     * @brief // Shortstory <BR>
//     * iStat = oTestBase.Func_1(iKey);
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//    // int Func_1(int iKey);
//// ----------------------------------------------------------------------------
//     //==============================================================================
//     /**
//     * @brief // Shortstory <BR>
//     * iStat = oCsvArc.Func_1(iKey)
//     *
//     * @param iKey [in] For the moment 0
//     * @param sErrTxt [in] For the moment 0
//     * @param ssstDxfLib_Str [in] For the moment 0
//     * @param osstDxf02TypMainCls [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int Csv_Read(int iKey,
//                  std::string *sErrTxt,
//                  std::string *ssstDxfLib_Str,
//                  sstDxf02TypMainCls *osstDxf02TypMainCls);  // Csv Read Function
//     //==============================================================================
//     /**
//     * @brief // Shortstory <BR>
//     * iStat = oCsvArc.Func_1(iKey)
//     *
//     * @param iKey [in] For the moment 0
//     * @param osstDxf02TypArcCls [in] For the moment 0
//     * @param ssstDxfLib_Str [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int Csv_Write(int iKey,
//                   sstDxf02TypMainCls *osstDxf02TypMainCls,
//                   std::string *ssstDxfLib_Str);  // Csv Write Function
//     //==============================================================================
//     /**
//     * @brief // write ARC titel row to csv file <BR>
//     * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
//     *
//     * @param iKey    [in]  For the moment 0
//     * @param oCsvStr [out] return string titel row
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int Csv_WriteHeader(int iKey, std::string *oCsvStr);
//     //==============================================================================
//     /**
//     * @brief // Read whole layer csv file into sst_rec_mem <BR>
//     * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
//     *
//     * @param iKey    [in] For the moment 0
//     * @param oFilNam [in] File name to import to rec mem
//     *
//     * @return Errorstate
//     *
//     * @retval   =  0: OK
//     * @retval   = -1: Wrong Key
//     * @retval   = -2: Open File Error
//     * @retval   = -3: General read error
//     * @retval   = -4: Record format read Error
//     * @retval   <  0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int ReadCsvFile(int iKey, std::string oFilNam);
//     //==============================================================================
//private:  // Private functions
//int Dum;        /**< Dummy */
//};
////-----------------------------------------------------------------------------

////==============================================================================
///**
//* @brief Definition Class sstTestBaseInternCls
//*
//* template for sst base class <BR>
//*
//* Changed: 08.07.15  Re.
//*
//* @ingroup sstDxf02Lib
//*
//* @author Re.
//*
//* @date 08.07.15
//*/
//// ----------------------------------------------------------------------------
//class sstDxf01WriteCls
//{
//  public:   // Public functions
//     sstDxf01WriteCls(sstDxf01DatabaseCls *oDxfDB);  // Constructor
//    ~sstDxf01WriteCls();  // Destructor
//     //==============================================================================
//     /**
//     * @brief // Shortstory <BR>
//     * oTestBase.Func_1(iKey)
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int FileOpen (int         iKey);
//     //==============================================================================
//     /**
//     * @brief // Shortstory <BR>
//     * oTestBase.Func_1(iKey)
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int FileClose (int          iKey);
//     //==============================================================================
//     /**
//     * @brief // Write dxf section header <BR>
//     * iStat = oSstDxfWrite.WrtSecHeader(iKey);
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int WrtSecHeader (int         iKey);
//     //==============================================================================
//     /**
//     * @brief // Write Dxf Section layers <BR>
//     * iStat = oSstDxfWrite.WrtSecLayers(iKey);
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int WrtSecLayers (int         iKey);
//     //==============================================================================
//     /**
//     * @brief // Write Dxf Section Blocks <BR>
//     * iStat = oSstDxfWrite.WrtSecBlocks(iKey);
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int WrtSecBlocks (int         iKey);
//     //==============================================================================
//     /**
//     * @brief // Write Dxf Section Types <BR>
//     * iStat = oSstDxfWrite.WrtSecTypes(iKey);
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int WrtSecTypes (int          iKey);
//     //==============================================================================
//     /**
//     * @brief // Write Dxf Sectin Styles <BR>
//     * iStat = oSstDxfWrite.WrtSecStyles(iKey);
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int WrtSecStyles (int          iKey);
//     //==============================================================================
//     /**
//     * @brief // Shortstory <BR>
//     * iStat = oSstDxfWrite.Func_1(iKey)
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int WrtSecEntities (int          iKey);
//     //==============================================================================
//     /**
//     * @brief // Write Dxf Section objects <BR>
//     * iStat = oSstDxfWrite.WrtSecObjects(iKey)
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int WrtSecObjects (int          iKey);
//     //==============================================================================
//     /**
//     * @brief // Write Polyline into section entities <BR>
//     * iStat = oSstDxfWrite.WrtDss2Polyline(iKey,sPntDss);
//     *
//     * @param iKey    [in] For the moment 0
//     * @param sPntDss [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int WrtDss2PolyLine (int           iKey,
//                          sstRec04Cls  *sPntDss);
//// ----------------------------------------------------------------------------
//private:  // Private functions
//  DL_Dxf* dxf;     /**< dxflib dxf */
//  DL_WriterA* dw;  /**< dxflib dw */
//  sstDxf01DatabaseCls *oDxfDB; /**< sst dxf database */

//};
////-----------------------------------------------------------------------------
////==============================================================================
///**
//* @brief sst dxf database class
//*
//* Stores all dxf types <BR>
//*
//* Changed: 06.04.16  Re.
//*
//* @ingroup sstDxf02Lib
//*
//* @author Re.
//*
//* @date 06.04.16
//*/
//// ----------------------------------------------------------------------------
//class sstDxf01DatabaseCls
//{
//  public:   // Public functions
//     sstDxf01DatabaseCls(sstMisc01PrtFilCls *oTmpPrt);  // Constructor
//    //~sstTestBaseCls();  // Destructor
//     //==============================================================================
//     /**
//     * @brief // Read all Csv Files into dxf database <BR>
//     * iStat = oSstDxfDB.ReadAllCsvFiles(iKey);
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//     int ReadAllCsvFiles(int iKey, std::string oDxfFilNam);
//// ----------------------------------------------------------------------------
//     sstDxf02FncLayCls* getSstFncLay();
//     void setSstFncLay(const sstDxf02FncLayCls &value);

//     sstDxf02FncBlkCls* getSstFncBlk();
//     void setSstFncBlk(const sstDxf02FncBlkCls &value);

//     sstDxf02FncArcCls* getSstFncArc();
//     void setSstFncArc(const sstDxf02FncArcCls &value);

//     sstDxf02FncInsertCls* getSstFncInsert();
//     void setSstFncInsert(const sstDxf02FncInsertCls &value);

//private:  // Private functions
//  sstDxf02FncLayCls oSstFncLay;        /**< layer recmem object */
//  sstDxf02FncBlkCls oSstFncBlk;        /**< Block recmem object */
//  sstDxf02FncArcCls oSstFncArc;        /**< Arc recmem object */
//  sstDxf02FncInsertCls oSstFncInsert;  /**< Insert recmem object */
//  sstDxf02FncMainCls oSstFncMain;      /**< Main recmem object */
//  sstMisc01PrtFilCls *oPrt;            /**< Protocol object */

//};
////==============================================================================
///**
//* @brief Definition Class sstDxf02EntityTypeCls
//*
//* Classes and functions for LibreCAD enum EntityType <BR>
//*
//* Changed: 08.07.15  Re.
//*
//* @ingroup sstDxf02Lib
//*
//* @author Re.
//*
//* @date 08.07.15
//*/
//// ----------------------------------------------------------------------------
//class sstDxf02EntityTypeCls
//{
//  public:   // Public functions
//     sstDxf02EntityTypeCls();  // Constructor
//    //~sstTestBaseCls();  // Destructor
//     //==============================================================================
//     /**
//     * @brief // converts enum to string <BR>
//     * oString = oEntityType.Enum2String(eType);
//     *
//     * @param eType [in] For the moment 0
//     *
//     * @return Type as string
//     */
//     // ----------------------------------------------------------------------------
//     std::string Enum2String(RS2::EntityType eType);
//     //==============================================================================
//     /**
//     * @brief // converts string to enum <BR>
//     * eType = oEntityType.String2Enum(oTypeString);
//     *
//     * @param eType [in] For the moment 0
//     *
//     * @return Type as string
//     */
//     // ----------------------------------------------------------------------------
//     RS2::EntityType String2Enum(std::string oTypeString);
//// ----------------------------------------------------------------------------
//private:  // Private functions
//int Dum;        /**< Dummy */
//};
////-----------------------------------------------------------------------------


#endif // SSTDXF2CSV_H

