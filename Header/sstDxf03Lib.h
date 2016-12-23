/**********************************************************************
 *
 * sstDxf03Lib - sst dxf library
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
// sstDxf03Lib.h   22.02.16  Re.   22.02.16  Re.
//
// Datastructures and Prototypes for system "sstDxf03Lib"
//
  
#ifndef   _SST_DXF03LIB_HEADER
#define   _SST_DXF03LIB_HEADER

/**
 * @defgroup sstDxf03Lib sstDxf03Lib: cpp sst dxf library (Version 3)
 *
 * cpp sst dxf library <BR>
 *
 */

// forward declaration ---------------------------------------------------------

class sstDxf03DatabaseCls;

//==============================================================================
/**
* @brief Storage Class for dxflib elements
*
* splits dxf data into tables with import/export of CSV-Datatypes. <BR>
*
* Changed: 09.07.15  Re.
*
* @ingroup sstDxf03Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf03DbCls
{
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // Constructor of sstDxfDb <BR>
  * sstDxf03DbCls oDxfDB(&oPrt);
  *
  * @param oPrt       [in] Adress of protocol objekt
  */
  // ----------------------------------------------------------------------------
  sstDxf03DbCls(sstMisc01PrtFilCls *oPrt);  // Constructor
 ~sstDxf03DbCls();  // Destructor
  //==============================================================================
  /**
  * @brief // write new dxflib circle into sstDxfDb <BR>
  * iStat = oDxfDb.WriteNewCicle (iKey, oDLCircle, Attributes, &oEntRecNo, &oMainRecNo);
  *
  * @param iKey       [in] For the moment 0
  * @param oDLCircle  [in] dxflib circle
  * @param attributes [in] dxflib attributes
  * @param oEntRecNo  [out] return record number in entity table
  * @param oMainRecNo [out] Return Record number in main table
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WriteNewCircle(int iKey,
                     const DL_CircleData oDLCircle,
                     const DL_Attributes attributes,
                     dREC04RECNUMTYP *oEntRecNo,
                     dREC04RECNUMTYP *oMainRecNo);
  //==============================================================================
  /**
  * @brief // open new dxflib hatch object in sstDxfDb <BR>
  * iStat = oDxfDb.OpenNewHatch (iKey, oDLHatch, Attributes, &oEntRecNo, &oMainRecNo);
  *
  * @param iKey          [in] For the moment 0
  * @param oDLHatch      [in] dxflib hatch
  * @param oDLAttributes [in] dxflib attributes
  * @param oEntRecNo     [out] return record number in entity table
  * @param oMainRecNo    [out] Return Record number in main table
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int OpenNewHatch(int                  iKey,
                   const DL_HatchData   oDLHatch,
                   const DL_Attributes  oDLAttributes,
                   dREC04RECNUMTYP     *oEntRecNo,
                   dREC04RECNUMTYP     *oMainRecNo);
  //==============================================================================
  /**
  * @brief // write new dxflib hatch edge into sstDxfDb  hatch object <BR>
  * iStat = oDxfDb.WriteNewHatchEdge (iKey, oDLHatchEdge, &oEntRecNo, &oMainRecNo);
  *
  * @param iKey          [in] For the moment 0
  * @param oDLHatchEdge  [in] dxflib hatch edge
  * @param oEntRecNo     [out] return record number in entity table
  * @param oMainRecNo    [out] Return Record number in main table
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WriteNewHatchEdge (int                    iKey,
                         const DL_HatchEdgeData oDLHatchEdge,
                         dREC04RECNUMTYP       *oEntRecNo,
                         dREC04RECNUMTYP       *oMainRecNo);
  //==============================================================================
  /**
  * @brief // Write whole sst dxf database into dxf file. <BR>
  * iStat = oDxfDb.WritAll2DxfFil ( iKey, oDxfFilNam);
  *
  * @param iKey [in] For the moment 0
  * @param oDxfFilNam [in] Dxf File Name
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WritAll2DxfFil(int iKey, const std::string oDxfFilNam);
  //==============================================================================
  /**
  * @brief // Writes all stored dxf data into several CSV-Files. <BR>
  * iStat = oDxfDb.WritAll2Csv(iKey,oDxfFilNam);
  *
  * Write FilNam_Main.csv  <BR>
  *       FilNam_Layer.csv <BR>
  *       FilNam_Block.csv <BR>
  *       FilNam_Line.csv  and so on. <BR>
  *
  * @param iKey [in] For the moment 0
  * @param oDxfFilNam [in] Root Name of Csv-Files
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WritAll2Csv(int iKey, const std::string oDxfFilNam);
  //==============================================================================
  /**
  * @brief // Read all Csv Files and rebuild dxf database <BR>
  * iStat = oSstDxfDB.ReadAllCsvFiles(iKey);
  *
  * @param iKey       [in] For the moment 0
  * @param oDxfFilNam [in] Root Name of all Csv files
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadAllCsvFiles(int iKey, std::string oDxfFilNam);
  //==============================================================================
  /**
  * @brief // store whole dxf file into sst Dxf Database <BR>
  * iStat = oDxfDb.ReadAllFromDxf( iKey, oDxfFilNam);
  *
  * @param iKey [in] For the moment 0
  * @param oDxfFilNam [in] Name of Dxf file to be stored
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadAllFromDxf(int iKey, const std::string oDxfFilNam);
  //==============================================================================
  /**
  * @brief // return number of records in main table <BR>
  * dMainRecs = oDxfDb.MainCount();
  *
  * @return Number of records in main table
  */
  // ----------------------------------------------------------------------------
  dREC04RECNUMTYP MainCount();
  //==============================================================================
  /**
  * @brief // return number of records in entity table <BR>
  * dMainRecs = oDxfDb.EntityCount(eEntityType);
  *
  * @param eEntityType [in] specify entity type
  *
  * @return Number of records in entity table
  */
  // ----------------------------------------------------------------------------
  dREC04RECNUMTYP EntityCount(RS2::EntityType eEntityType);
  //==============================================================================
  /**
  * @brief // Read hatch from table with attributes <BR>
  * iStat = oDxfDb.ReadHatch( iKey, &oDLHatch, &oDLAttributes);
  *
  * @param iKey [in] For the moment 0
  * @param dRecNo [int] Record number in table
  * @param oDLHatch [out] Return Hatch
  * @param oDLAttributes [out] Return Hatch attributes
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadHatch ( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchData *oDLHatch, DL_Attributes *oDLAttributes);
  //==============================================================================
  /**
  * @brief // Read hatch edge from table <BR>
  * iStat = oDxfDb.ReadHatchEdge( iKey, dRecNo, &oDLHatchEdge);
  *
  * @param iKey [in] For the moment 0
  * @param dRecNo [int] Record number in table
  * @param oDLHatchEdge [out] Return Hatch Edge
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadHatchEdge( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchEdgeData *oDLHatchEdge);
  //==============================================================================
  /**
  * @brief // Read hatch loop from table <BR>
  * iStat = oDxfDb.ReadHatchLoop( iKey, dRecNo, &oDLHatchLoop);
  *
  * @param iKey [in] For the moment 0
  * @param dRecNo [int] Record number in table
  * @param oDLHatchLoop [out] Return Hatch Loop
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadHatchLoop( int iKey, dREC04RECNUMTYP dRecNo, DL_HatchLoopData *oDLHatchLoop);
  //==============================================================================
  /**
  * @brief // Read circle from table with attributes <BR>
  * iStat = oDxfDb.ReadCircle( iKey, &oDLCircle, &oDLAttributes);
  *
  * @param iKey [in] For the moment 0
  * @param dRecNo [int] Record number in table
  * @param oDLCircle [out] Return Circle
  * @param oDLAttributes [out] Return Circle attributes
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadCircle ( int iKey, dREC04RECNUMTYP dRecNo, DL_CircleData *oDLCircle, DL_Attributes *oDLAttributes);
  //==============================================================================
  /**
  * @brief // Read entity information from main table <BR>
  * iStat = oDxfDb.ReadMainTable( iKey, dRecNo, &eEntityType, &dEntRecNo);
  *
  * @param iKey        [in] For the moment 0
  * @param dMainRecNo  [int] Record number in main table
  * @param eEntityType [out] return entity type
  * @param dEntRecNo   [out] return record number in entity table
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadMainTable( int iKey, dREC04RECNUMTYP dMainRecNo, RS2::EntityType *eEntityType, dREC04RECNUMTYP *dEntRecNo);
  //==============================================================================


// ----------------------------------------------------------------------------
  private:  // Private functions
    sstDxf03DatabaseCls *poDxf03DbIntern;   /**< Pointer to intern object */
};
//==============================================================================
///**
//* @brief Helper Class for DL_Attibutes
//*
//* Changed: 09.07.15  Re.
//*
//* @ingroup sstTemplateLib
//*
//* @author Re.
//*
//* @date 09.07.15
//*/
//// ----------------------------------------------------------------------------
//class sstDxf03AttribHlpCls
//{
//  public:   // Public functions
//     sstDxf03AttribHlpCls();  // Constructor
//    //~sstTestBaseCls();  // Destructor
//     //==============================================================================
//     /**
//     * @brief // Set Layername to DL_Attribute <BR>
//     * iStat = oObj.Func_1(iKey);
//     *
//     * @param iKey [in] For the moment 0
//     *
//     * @return Errorstate
//     *
//     * @retval   = 0: OK
//     * @retval   < 0: Unspecified Error
//     */
//     // ----------------------------------------------------------------------------
//    // Func_1(int iKey);
//    void SetLayerNam(DL_Attributes *DL_Attribute, const std::string oLayNam);

//// ----------------------------------------------------------------------------
//  private:  // Private functions
//  int Dum;        /**< Dummy */
//};
//-----------------------------------------------------------------------------

#endif
//
// --------------------------------------------------------------- File End ----

