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
// sstDxf03Lib.h   23.02.18  Re.   22.02.16  Re.
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
  * @brief // write new dxflib circle  into sstDxfDb or rewrite existing <BR>
  * iStat = oDxfDb.WriteCicle (iKey, oDLCircle, Attributes, &oEntRecNo, &oMainRecNo);
  *
  * @param iKey          [in] For the moment 0
  * @param oDlCircle     [in] dxflib circle
  * @param oDlAttributes [in] dxflib attributes
  * @param oEntRecNo     [out] return record number in entity table
  * @param oMainRecNo    [out] Return Record number in main table
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WriteCircle (int                   iKey,
                   const DL_CircleData   oDlCircle,
                   const DL_Attributes   oDlAttributes,
                   dREC04RECNUMTYP      *oEntRecNo,
                   dREC04RECNUMTYP      *oMainRecNo);
  //==============================================================================
  /**
  * @brief // Rewrite existing or write new Line entity into dxf database <BR>
  * iStat = oDxfDbInt.WriteLine (iKey,oDLLine,oDLAttributes, &oEntRecNo, &oMainRecNo);
  *
  * @param iKey          [in] For the moment 0
  * @param oDLLine       [in] Line Entity
  * @param oDLAttributes [in] Entity attributes
  * @param oEntRecNo     [in out] =0: New, record number
  * @param oMainRecNo    [out] record number in main table
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WriteLine (int iKey,
                 const DL_LineData    oDLLine,
                 const DL_Attributes  oDLAttributes,
                 dREC04RECNUMTYP     *oEntRecNo,
                 dREC04RECNUMTYP     *oMainRecNo);
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
  * dEntityRecs = oDxfDb.EntityCount(eEntityType);
  *
  * for example:
  * RS2::EntityPoint, RS2::EntityLine, RS2::EntityPolyline, RS2::EntityVertex
  *
  * @param eEntityType [in] specify entity type
  *
  * @return Number of records in entity table
  */
  // ----------------------------------------------------------------------------
  dREC04RECNUMTYP EntityCount(RS2::EntityType eEntityType);
  //==============================================================================
  /**
  * @brief // ColumnCount <BR>
  * iStat = oDxfDb.ColumnCount ( eEntityType);
  *
  * @param eEntityType [in] Entity Type e.g. RS2::EntityLine
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // -----------------------------------------------------------------------------
  int ColumnCount(RS2::EntityType eEntityType);
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
  * @brief // Read hatch edge element from table <BR>
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
  * @brief // Read hatch loop element from table <BR>
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
  * @brief // Read vertex from table with attributes <BR>
  * iStat = oDxfDb.ReadVertex( iKey, &oDLVertex, &oDLAttributes);
  *
  * @param iKey [in] For the moment 0
  * @param dRecNo [int] Record number in table
  * @param oDLVertex [out] Return Vertex
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadVertex ( int iKey, dREC04RECNUMTYP dRecNo, DL_VertexData *oDLVertex);
  //==============================================================================
  /**
  * @brief // Read line from table with attributes <BR>
  * iStat = oDxfDb.ReadLine ( iKey, dRecNo, &oDLLine, &oDLAttributes);
  *
  * @param iKey          [in]  For the moment 0
  * @param dRecNo        [int] Record number in line table
  * @param oDLLine       [out] Return Line
  * @param oDLAttributes [out] Return Line attributes
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadLine ( int iKey,
                 dREC04RECNUMTYP dRecNo,
                 DL_LineData *oDLLine,
                 DL_Attributes *oDLAttributes);
  //==============================================================================
  /**
  * @brief // Read polyline from table with attributes <BR>
  * iStat = oDxfDb.ReadPolyline ( iKey, dRecNo, &oDLPolyline, &oDLAttributes);
  *
  * @param iKey          [in]  For the moment 0
  * @param dRecNo        [int] Record number in line table
  * @param oDLPolyline   [out] Return Polyline
  * @param oDLAttributes [out] Return Attributes
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadPolyline ( int iKey, dREC04RECNUMTYP dRecNo, DL_PolylineData *oDLPolyline, DL_Attributes *oDLAttributes);
  //==============================================================================
  /**
  * @brief // Read block from table with attributes <BR>
  * iStat = oDxfDb.ReadBlock ( iKey, dRecNo, &oDLBlock, &oDLAttributes);
  *
  * @param iKey          [in]  For the moment 0
  * @param dRecNo        [int] Record number in line table
  * @param oDLBlock      [out] Return Block
  * @param oDLAttributes [out] Return Attributes
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadBlock ( int iKey, dREC04RECNUMTYP dRecNo, DL_BlockData *oDLBlock, DL_Attributes *oDLAttributes);
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
  /**
  * @brief // Get Minimum Bounding rectangle from section entities /model space  <BR>
  *
  * @return Minimum Bounding rectangle
  */
  // ----------------------------------------------------------------------------
  sstMath01Mbr2Cls getMbrModel();
  //==============================================================================
  /**
  * @brief // Get Minimum Bounding rectangle of Block <BR>
  *
  * @param dBlkNo   [in] Block number
  *
  * @return Minimum Bounding rectangle
  */
  // ----------------------------------------------------------------------------
  sstMath01Mbr2Cls getMbrBlock(dREC04RECNUMTYP dBlkNo );
  //==============================================================================
  /**
  * @brief // return number of blocks in sstDxfDb <BR>
  * dNumBlocks = oDxfDb.countBlocks();
  *
  * @return Number of records in block table
  */
  // ----------------------------------------------------------------------------
  dREC04RECNUMTYP countBlocks();
  //==============================================================================
  /**
  * @brief // return number of entities in actual block in sstDxfDb <BR>
  * dNumEntities = oDxfDb.countEntities (iKey, dBlkNo);
  *
  * dBlcNo = 0:  Count entities of section entities
  *
  * @param iKey       [in] For the moment 0
  * @param dBlkNo     [in] Block number (=0: model space)
  *
  * @return Number of records in block table
  */
  // ----------------------------------------------------------------------------
  dREC04RECNUMTYP countEntities(int iKey, dREC04RECNUMTYP dBlkNo);
  //==============================================================================
  /**
  * @brief // return type/Tab Rec No of entity in block with main tab no <BR>
  * iStat = oDxfDb.ReadEntityType (iKey, dBlkNo, dMainNo, &eEntType, &dEntNo);
  *
  * BlockNo=0;MainNo=1 = First Element in section entities
  *
  * @param iKey       [in] For the moment 0
  * @param dBlkNo     [in] Block number (=0: model space / section entities)
  * @param dMainNo    [in] Record Number in Main table
  * @param eEntType   [out] enum entity type
  * @param dEntNo     [out] Record Number in Entity table
  *
  * @return status
  */
  // ----------------------------------------------------------------------------
  int ReadEntityType(int iKey,
                     dREC04RECNUMTYP  dBlkNo,
                     dREC04RECNUMTYP  dMainNo,
                     RS2::EntityType *eEntType,
                     dREC04RECNUMTYP *dEntNo);
  //==============================================================================
  /**
  * @brief // write new point or rewrite existing <BR>
  * iStat = oDxfDb.WritePoint (iKey, oDlPoint, oDlAttributes, &oEntRecNo, &oMainRecNo);
  *
  * @param iKey          [in] For the moment 0
  * @param oDlPoint      [in] dxflib point
  * @param oDlAttributes [in] DL Attributes
  * @param oEntRecNo     [out] return record number in entity table
  * @param oMainRecNo    [out] Return Record number in main table
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WritePoint (int iKey,
                 const DL_PointData   oDlPoint,
                 const DL_Attributes  oDlAttributes,
                 dREC04RECNUMTYP     *oEntRecNo,
                 dREC04RECNUMTYP     *oMainRecNo);
  //==============================================================================
  /**
  * @brief // Read point from table with attributes <BR>
  * iStat = oDxfDb.ReadPoint ( iKey, dRecNo, &oDlPoint, &oDlAttributes);
  *
  * @param iKey          [in]  For the moment 0
  * @param dRecNo        [int] Record number in line table
  * @param oDlPoint      [out] Return Point
  * @param oDlAttributes [out] Return DL attributes
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadPoint ( int               iKey,
                  dREC04RECNUMTYP   dRecNo,
                  DL_PointData     *oDlPoint,
                  DL_Attributes    *oDlAttributes);
  //==============================================================================
  /**
  * @brief // write new point or rewrite existing <BR>
  * iStat = oDxfDb.WritePoint (iKey, oDlMText, oDlAttributes, &oEntRecNo, &oMainRecNo);
  *
  * @param iKey          [in] For the moment 0
  * @param oDlMText      [in] dxflib MText
  * @param oDlAttributes [in] DL Attributes
  * @param oEntRecNo     [out] return record number in entity table
  * @param oMainRecNo    [out] Return Record number in main table
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WriteMText (int iKey,
                 const DL_MTextData   oDlMText,
                 const DL_Attributes  oDlAttributes,
                 dREC04RECNUMTYP     *oEntRecNo,
                 dREC04RECNUMTYP     *oMainRecNo);
  //==============================================================================
  /**
  * @brief // Read MText from table with attributes <BR>
  * iStat = oDxfDb.ReadMText ( iKey, dRecNo, &oDlMText, &oDlAttributes);
  *
  * @param iKey          [in]  For the moment 0
  * @param dRecNo        [int] Record number in line table
  * @param oDlMText      [out] Return MText
  * @param oDlAttributes [out] Return DL attributes
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadMText ( int              iKey,
                  dREC04RECNUMTYP  dRecNo,
                  DL_MTextData    *oDlMText,
                  DL_Attributes   *oDlAttributes);
  //==============================================================================
  /**
  * @brief // write new text or rewrite existing <BR>
  * iStat = oDxfDb.WriteText (iKey, oDlText, oDlAttributes, &oEntRecNo, &oMainRecNo);
  *
  * @param iKey          [in] For the moment 0
  * @param oDlText       [in] dxflib Text
  * @param oDlAttributes [in] DL Attributes
  * @param oEntRecNo     [out] return record number in entity table
  * @param oMainRecNo    [out] Return Record number in main table
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int WriteText (int iKey,
                 const DL_TextData    oDlText,
                 const DL_Attributes  oDlAttributes,
                 dREC04RECNUMTYP     *oEntRecNo,
                 dREC04RECNUMTYP     *oMainRecNo);
  //==============================================================================
  /**
  * @brief // Read text from table with attributes <BR>
  * iStat = oDxfDb.ReadText ( iKey, dRecNo, &oDlText, &oDLAttributes);
  *
  * @param iKey          [in]  For the moment 0
  * @param dRecNo        [int] Record number in line table
  * @param oDlText       [out] Return text
  * @param oDlAttributes [out] Return DL attributes
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int ReadText ( int              iKey,
                 dREC04RECNUMTYP  dRecNo,
                 DL_TextData     *oDlText,
                 DL_Attributes   *oDlAttributes);
  //==============================================================================
  /**
  * @brief // Generate dxf data in utm area (Germany)  <BR>
  * iStat = oDxfDb.GenerateData ( iKey, &oPrt);
  *
  * @param iKey [in] For the moment 0
  *
  * @return Errorstate
  *
  * @retval   = 0: OK
  * @retval   < 0: Unspecified Error
  */
  // ----------------------------------------------------------------------------
  int GenerateData ( int iKey);
  //==============================================================================
  /**
  * @brief // convert Entity Type enum to string <BR>
  * oeEntityString = oDxfDB.CnvtTypeEnum2String ( eEntityType);
  *
  * @param eEntityType [in] Entity Enum
  *
  * @return Entity Type String
  */
  // ----------------------------------------------------------------------------
  std::string CnvtTypeEnum2String(RS2::EntityType eEntityType);
  //==============================================================================
  /**
  * @brief // convert Entity String to enum <BR>
  * eEntityType = oDxfDB.CnvtTypeString2Enum ( oEntityStr);
  *
  * @param oEntityStr [in] Entity String
  *
  * @return Entity Enum
  */
  // ----------------------------------------------------------------------------
  RS2::EntityType CnvtTypeString2Enum(std::string oEntityStr);
  //==============================================================================
  private:  // Private functions
    sstDxf03DatabaseCls *poDxf03DbIntern;   /**< Pointer to intern object */
};
//==============================================================================

#endif

//
// --------------------------------------------------------------- File End ----

