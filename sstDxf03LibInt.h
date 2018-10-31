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
// sstDxf03LibInt.h   23.02.18  Re.   02.11.16  Re.
//
// Intern Datastructures and Prototypes for system "sstDxf03LibInt"
//

#ifndef   _SST_DXF03_LIB_INT_HEADER
#define   _SST_DXF03_LIB_INT_HEADER

/**
 * @defgroup sstDxf03LibInt sstDxf03LibInt
 * intern library for sst dxf
 */


// Defines ---------------------------------------------------------------------

// Structures and Classes ------------------------------------------------------


#define dSSTDXF03LAYERNAMELEN   256  /**< Layer Name length @ingroup sstDxf03Lib */
#define dSSTDXF03BLOCKNAMELEN   256  /**< Block Name length @ingroup sstDxf03Lib */
#define dSSTDXF03LTYPENAMELEN   256  /**< LineType Name length @ingroup sstDxf03Lib */

//==============================================================================
/**
* @brief Definition Class sstDxf03EntityTypeCls
*
* Classes and functions for LibreCAD enum EntityType <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf03EntityTypeCls
{
  public:   // Public functions
     sstDxf03EntityTypeCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // converts enum to string <BR>
     * oString = oEntityType.Enum2String(eType);
     *
     * @param eType [in] For the moment 0
     *
     * @return Type as string
     */
     // ----------------------------------------------------------------------------
     std::string Enum2String(RS2::EntityType eType);
     //==============================================================================
     /**
     * @brief // converts string to enum <BR>
     * eType = oEntityType.String2Enum(oTypeString);
     *
     * @param oTypeString [in] Entity as string
     *
     * @return Type as librecad enum
     */
     // ----------------------------------------------------------------------------
     RS2::EntityType String2Enum(std::string oTypeString);
// ----------------------------------------------------------------------------
private:  // Private functions
// int Dum;        /**< Dummy */
};
//==============================================================================
/**
* @brief sst dxf base class for dxf types
*
* More Comment
*
* Changed: 03.03.16  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 03.03.16
**/
//------------------------------------------------------------------------
class sstDxf03TypBaseCls
{
  public:
    sstDxf03TypBaseCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getColor() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setColor(int value);
    //==============================================================================
    /**
    * @brief // read attribu data from dxflib arc <BR>
    * oSstDxfArc.BaseReadFromDL(oDLAttrib);
    *
    * @param oDLAttrib [in] dxflib attribut structure
    */
    // ----------------------------------------------------------------------------
    void BaseReadFromDL(const DL_Attributes oDLAttrib);
    //==============================================================================
    /**
    * @brief // write attribute data to dxflib attribut <BR>
    * oSstDxfBase.BaseWritToDL(poDLAttrib);
    *
    * @param poDLAttrib [out] dxflib arc structure
    */
    // ----------------------------------------------------------------------------
    void BaseWritToDL(DL_Attributes *poDLAttrib);

    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getBlockID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    void setBlockID(const dREC04RECNUMTYP &value);

    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getLayerID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    void setLayerID(const dREC04RECNUMTYP &value);

    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getRecordID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    void setRecordID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getLinetypeID() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setLinetypeID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getColor24() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setColor24(int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getWidth() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setWidth(int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getHandle() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set Value
    */
    // ----------------------------------------------------------------------------
    void setHandle(int value);
    //==============================================================================

private:
    // standard attributes
    dREC04RECNUMTYP dRecordID;   /**< Identifier in Element table */
    dREC04RECNUMTYP dLayerID;    /**< Identifier in Layer table */
    dREC04RECNUMTYP dBlockID;    /**< Identifier in Block table */
    dREC04RECNUMTYP dLinetypeID; /**< Identifier in Linetype table */
    int color;                   /**< color */
    int color24;                 /**< color24 */
    int width;                   /**< width */
    int handle;                  /**< handle */
};
//==============================================================================
/**
* @brief LineType record class
*
* LineType record class <BR>
*
* Changed: 10.06.16  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 10.06.16
*/
// ----------------------------------------------------------------------------
class sstDxf03TypLTypeCls
{
  public:   // Public functions
     sstDxf03TypLTypeCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Set Linetype name <BR>
     * oSstDxfLType.setName(iKey)
     *
     * @param oName [in] Set Name
     */
     // ----------------------------------------------------------------------------
     void setName(const std::string oName);
     //==============================================================================
     /**
     * @brief // Get LineType Name <BR>
     * oSstDxfLType.getName(iKey)
     *
     * @return char Name
     */
     // ----------------------------------------------------------------------------
     char* getName();
     //==============================================================================
     /**
     * @brief // Get Size of Linetype Name <BR>
     * iSizeNam = oSstDxfLType.GetSizeName();
     *
     * @return int size of name
     */
     // ----------------------------------------------------------------------------
     int getSizeName() const;
     //==============================================================================
     /**
     * @brief // Get Linetype ID <BR>
     * dLineTypeID = oSstDxfLType.GetLineTypeID();
     *
     * @return Linetype ID
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getLineTypeID() const;
     //==============================================================================
     /**
     * @brief // Set Linetype ID <BR>
     * oSstDxfLType.setLineTypeID(value);
     *
     * @param value [in] Linetype ID
     */
     // ----------------------------------------------------------------------------
     void setLineTypeID(const dREC04RECNUMTYP &value);
     //==============================================================================

private:  // Private functions
     dREC04RECNUMTYP dLineTypeID;   /**< Linetype ID */
     char Nam[dSSTDXF03LTYPENAMELEN]; /**< Linetype Name */
};
//==============================================================================
/**
* @brief sst Dxf Arc Class
*
* More Comment
*
* Used Type Definitions
* sstDxf03;Arc;cx;DD;12;4;sst Dxf Lib;sst Arc;X Coordinate of center point
* sstDxf03;Arc;cy;DD;12;4;sst Dxf Lib;sst Arc;Y Coordinate of center point
* sstDxf03;Arc;cz;DD;12;4;sst Dxf Lib;sst Arc;Z Coordinate of center point
* sstDxf03;Arc;radius;DD;12;4;sst Dxf Lib;sst Arc;Radius of arc
* sstDxf03;Arc;angle1;DD;12;4;sst Dxf Lib;sst Arc;Startangle of arc in degrees
* sstDxf03;Arc;angle2;DD;12;4;sst Dxf Lib;sst Arc;Endangle of arc in degrees
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf03TypArcCls : public sstDxf03TypBaseCls
{
  public:
    sstDxf03TypArcCls();  // Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfArc.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // read arc data from dxflib arc <BR>
    * oSstDxfArc.ReadFromDL(poDLArc);
    *
    * @param poDLArc [in] dxflib arc structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_ArcData poDLArc);
    //==============================================================================
    /**
    * @brief // write arc data to dxflib arc <BR>
    * oSstDxfArc.WritToDL(poDLArc);
    *
    * @param poDLArc [out] dxflib arc structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_ArcData *poDLArc);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getCx() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setCx(double value);

    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getCy() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setCy(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getCz() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setCz(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getRadius() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setRadius(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getAngle1() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setAngle1(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getAngle2() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setAngle2(double value);
    //==============================================================================
    /**
    * @brief // Get Layer ID  <BR>
    *
    * @return LayerID
    */
    // ----------------------------------------------------------------------------
    // unsigned long getLayerID() const;
    //==============================================================================
    /**
    * @brief // Set Layer ID  <BR>
    *
    * @param value [in] Set Layer ID
    */
    // ----------------------------------------------------------------------------
    // void setLayerID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get Block ID  <BR>
    *
    * @return BlockID
    */
    // ----------------------------------------------------------------------------
    // unsigned long getBlockID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    // void setBlockID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    // unsigned long getArcID() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    // void setArcID(unsigned long value);
    //==============================================================================

private:
//    dREC04RECNUMTYP ulArcID;
//    dREC04RECNUMTYP ulLayerID;
//    dREC04RECNUMTYP ulBlockID;
    double cx;
    double cy;
    double cz;
    double radius;
    double angle1;
    double angle2;
};
//==============================================================================//==============================================================================
/**
* @brief sst Dxf insert Class
*
* storable insert record
*
* Used Type Definitions
* sstDxf03;Insert;name;CC;256;0;sst Dxf Lib;sst Insert;Name of the referred block
* sstDxf03;Insert;ipx;DD;12;4;sst Dxf Lib;sst Insert;X Coordinate of insertion point
* sstDxf03;Insert;ipy;DD;12;4;sst Dxf Lib;sst Insert;Y Coordinate of insertion point
* sstDxf03;Insert;ipz;DD;12;4;sst Dxf Lib;sst Insert;Z Coordinate of insertion point
* sstDxf03;Insert;sx;DD;12;4;sst Dxf Lib;sst Insert;X Scale factor
* sstDxf03;Insert;sy;DD;12;4;sst Dxf Lib;sst Insert;Y Scale factor
* sstDxf03;Insert;sz;DD;12;4;sst Dxf Lib;sst Insert;Z Scale factor
* sstDxf03;Insert;angle;DD;12;4;sst Dxf Lib;sst Insert;Rotation angle in degrees
* sstDxf03;Insert;cols;II;6;0;sst Dxf Lib;sst Insert;Number of colums if we insert a
* sstDxf03;Insert;rows;II;6;0;sst Dxf Lib;sst Insert;Number of rows if we insert an
* sstDxf03;Insert;colSp;DD;12;4;sst Dxf Lib;sst Insert;Values for the spacing between
* sstDxf03;Insert;rowSp;DD;12;4;sst Dxf Lib;sst Insert;Values for the spacing between
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf03TypInsertCls : public sstDxf03TypBaseCls
{
  public:
    sstDxf03TypInsertCls();  // Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill Insert record from dxflib insert <BR>
    * oSstDxfInsert.ReadFromDL(poDLInsert);
    *
    * @param poDLInsert [in] dxflib Insert structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_InsertData poDLInsert);
    //==============================================================================
    /**
    * @brief // write Insert record data to dxflib insert <BR>
    * oSstDxfInsert.WritToDL(poDLInsert);
    *
    * @param poDLInsert [out] dxflib insert structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_InsertData *poDLInsert);
    //==============================================================================
    /**
    * @brief // Get insert ipx  <BR>
    *
    * @return double ipx
    */
    // ----------------------------------------------------------------------------
    double getIpx() const;
    //==============================================================================
    /**
    * @brief // Set insert ipx  <BR>
    *
    * @param value [in] ipx
    */
    // ----------------------------------------------------------------------------
    void setIpx(double value);
    //==============================================================================
    /**
    * @brief // Get insert ipy  <BR>
    *
    * @return double ipy
    */
    // ----------------------------------------------------------------------------
    double getIpy() const;
    //==============================================================================
    /**
    * @brief // Set insert ipy  <BR>
    *
    * @param value [in] ipy
    */
    // ----------------------------------------------------------------------------
    void setIpy(double value);
    //==============================================================================
    /**
    * @brief // Get insert ipz <BR>
    *
    * @return double ipz
    */
    // ----------------------------------------------------------------------------
    double getIpz() const;
    //==============================================================================
    /**
    * @brief // Set insert ipz  <BR>
    *
    * @param value [in] ipz
    */
    // ----------------------------------------------------------------------------
    void setIpz(double value);
    // sstDxf03TypBaseCls getBaseAttributes();

private:

//    unsigned long ulInsertID; // record number of Insert
//    unsigned long ulLayerID;  // record number of Layer
//    unsigned long ulBlockID;  // record number of Block

    /*! Name of the referred block. */
    // std::string name;
    /*! X Coordinate of insertion point. */
    double ipx;
    /*! Y Coordinate of insertion point. */
    double ipy;
    /*! Z Coordinate of insertion point. */
    double ipz;
    /*! X Scale factor. */
    double sx;
    /*! Y Scale factor. */
    double sy;
    /*! Z Scale factor. */
    double sz;
    /*! Rotation angle in degrees. */
    double angle;
    /*! Number of colums if we insert an array of the block or 1. */
    int cols;
    /*! Number of rows if we insert an array of the block or 1. */
    int rows;
    /*! Values for the spacing between cols. */
    double colSp;
    /*! Values for the spacing between rows. */
    double rowSp;
};
//==============================================================================
/**
* @brief sst Dxf Hatch Class
*
* storable hatch record
*
* Used Type Definitions
* sstDxf03;Hatch;numLoops;II;6;0;sst Dxf Lib;sst Hatch;Number of boundary paths (loops
* sstDxf03;Hatch;solid;BB;1;0;sst Dxf Lib;sst Hatch;Solid fill flag (true=solid, fa
* sstDxf03;Hatch;scale;DD;12;4;;sst Dxf Lib;sst Hatch
* sstDxf03;Hatch;angle;DD;12;4;;sst Dxf Lib;sst Hatch
* sstDxf03;Hatch;dPatternID;UL;10;0;sst Dxf Lib;sst Hatch;Pattern name
* sstDxf03;Hatch;originX;DD;12;4;;sst Dxf Lib;sst Hatch
* sstDxf03;Hatch;originY;DD;12;4;;sst Dxf Lib;sst Hatch
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf03TypHatchCls : public sstDxf03TypBaseCls
{
  public:
    sstDxf03TypHatchCls();  // Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfHatch.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill Hatch record from dxflib hatch <BR>
    * oSstDxfHatch.ReadFromDL(poDLHatch);
    *
    * @param poDLHatch [in] dxflib Hatch structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_HatchData poDLHatch);
    //==============================================================================
    /**
    * @brief // write Hatch record data to dxflib hatch <BR>
    * oSstDxfHatch.WritToDL(poDLHatch);
    *
    * @param poDLHatch [out] dxflib hatch structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_HatchData *poDLHatch);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    int getNumLoops() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setNumLoops(int value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    bool getSolid() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setSolid(bool value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    double getScale() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setScale(double value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    double getAngle() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setAngle(double value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getPatternID() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setPatternID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    double getOriginX() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setOriginX(double value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    double getOriginY() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setOriginY(double value);
    //==============================================================================

private:
    int numLoops; /*! Number of boundary paths (loops). */
    bool solid; /*! Solid fill flag (true=solid, false=pattern). */
    double scale;  /*! Pattern scale or spacing */
    double angle;  /*! Pattern angle in degrees */
    // std::string pattern;
    dREC04RECNUMTYP dPatternID;  /*! Pattern name. */
    double originX;  /*! Pattern origin */
    double originY;  /*! Pattern origin */
};
//==============================================================================
/**
* @brief sst Dxf Hatch Edge Class
*
* storable hatch edge record
*
* Used Type Definitions
* sstDxf03;HatchEdge;dRecordID;UL;10;0;sst Dxf Lib;sst HatchEdge;record id
* sstDxf03;HatchEdge;dParentID;UL;10;0;sst Dxf Lib;sst HatchEdge;Parent id
* sstDxf03;HatchEdge;defined;BB;1;0;sst Dxf Lib;sst HatchEdge;Set to true if this edge is ful
* sstDxf03;HatchEdge;type;II;6;0;sst Dxf Lib;sst HatchEdge;type. 1=line, 2=arc, 3=elliptic
* sstDxf03;HatchEdge;x1;DD;12;4;sst Dxf Lib;sst HatchEdge;Start point (X)
* sstDxf03;HatchEdge;y1;DD;12;4;sst Dxf Lib;sst HatchEdge;Start point (Y)
* sstDxf03;HatchEdge;x2;DD;12;4;sst Dxf Lib;sst HatchEdge;End point (X)
* sstDxf03;HatchEdge;y2;DD;12;4;sst Dxf Lib;sst HatchEdge;End point (Y)
* sstDxf03;HatchEdge;cx;DD;12;4;sst Dxf Lib;sst HatchEdge;Center point of arc or ellipse
* sstDxf03;HatchEdge;cy;DD;12;4;sst Dxf Lib;sst HatchEdge;Center point of arc or ellipse
* sstDxf03;HatchEdge;radius;DD;12;4;sst Dxf Lib;sst HatchEdge;Arc radius
* sstDxf03;HatchEdge;angle1;DD;12;4;sst Dxf Lib;sst HatchEdge;Start angle of arc or ellipse a
* sstDxf03;HatchEdge;angle2;DD;12;4;sst Dxf Lib;sst HatchEdge;End angle of arc or ellipse arc
* sstDxf03;HatchEdge;ccw;BB;1;0;sst Dxf Lib;sst HatchEdge;Counterclockwise flag for arc o
* sstDxf03;HatchEdge;mx;DD;12;4;sst Dxf Lib;sst HatchEdge;Major axis end point (X)
* sstDxf03;HatchEdge;my;DD;12;4;sst Dxf Lib;sst HatchEdge;Major axis end point (Y)
* sstDxf03;HatchEdge;ratio;DD;12;4;sst Dxf Lib;sst HatchEdge;Axis ratio
* sstDxf03;HatchEdge;degree;UI;6;0;sst Dxf Lib;sst HatchEdge;Spline degree
* sstDxf03;HatchEdge;rational;BB;1;0;sst Dxf Lib;sst HatchEdge;rational
* sstDxf03;HatchEdge;periodic;BB;1;0;sst Dxf Lib;sst HatchEdge;periodic
* sstDxf03;HatchEdge;nKnots;UI;6;0;sst Dxf Lib;sst HatchEdge;Number of knots
* sstDxf03;HatchEdge;nControl;UI;6;0;sst Dxf Lib;sst HatchEdge;Number of control points
* sstDxf03;HatchEdge;nFit;UI;6;0;sst Dxf Lib;sst HatchEdge;Number of fit points
* sstDxf03;HatchEdge;startTangentX;DD;12;4;sst Dxf Lib;sst HatchEdge;startTangentX
* sstDxf03;HatchEdge;startTangentY;DD;12;4;sst Dxf Lib;sst HatchEdge;startTangentY
* sstDxf03;HatchEdge;endTangentX;DD;12;4;sst Dxf Lib;sst HatchEdge;endTangentX
* sstDxf03;HatchEdge;endTangentY;DD;12;4;sst Dxf Lib;sst HatchEdge;entTangentY
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf03TypHatchEdgeCls  // : public sstDxf03TypBaseCls
{
  public:
    sstDxf03TypHatchEdgeCls();  // Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill hatch edge record from dxflib hatch edge <BR>
    * oSstDxfHatchEdge.ReadFromDL(poDLHatchEdge);
    *
    * @param poDLHatchEdge [in] dxflib Hatch edge structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_HatchEdgeData poDLHatchEdge);
    //==============================================================================
    /**
    * @brief // write hatch edge record data to dxflib hatch edge <BR>
    * oSstDxfHatchEdge.WritToDL(poDLHatchEdge);
    *
    * @param poDLHatchEdge [out] dxflib hatch edge structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_HatchEdgeData *poDLHatchEdge);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getRecordID() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setRecordID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    bool getDefined() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setDefined(bool value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getType() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setType(int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getX1() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setX1(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getY1() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setY1(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getX2() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setX2(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getY2() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setY2(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getCx() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setCx(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getCy() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setCy(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getRadius() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setRadius(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getAngle1() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setAngle1(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getAngle2() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setAngle2(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    bool getCcw() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setCcw(bool value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getMx() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setMx(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getMy() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setMy(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getRatio() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setRatio(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    unsigned int getDegree() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setDegree(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    bool getRational() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setRational(bool value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    bool getPeriodic() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setPeriodic(bool value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    unsigned int getNKnots() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setNKnots(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    unsigned int getNControl() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setNControl(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    unsigned int getNFit() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setNFit(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getStartTangentX() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setStartTangentX(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getStartTangentY() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setStartTangentY(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getEndTangentX() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setEndTangentX(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getEndTangentY() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setEndTangentY(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getParentID() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setParentID(const dREC04RECNUMTYP &value);
    //==============================================================================

private:
    dREC04RECNUMTYP dRecordID; /**< record id */
    dREC04RECNUMTYP dParentID; /**< Parent id */
    bool defined;  //  * Set to true if this edge is fully defined.
    int type;   // * Edge type. 1=line, 2=arc, 3=elliptic arc, 4=spline.
    double x1;  /*! Start point (X). */
    double y1;  /*! Start point (Y). */
    double x2;  /*! End point (X). */
    double y2;  /*! End point (Y). */
    double cx;  /*! Center point of arc or ellipse arc (X). */
    double cy;  /*! Center point of arc or ellipse arc (Y). */
    double radius;  /*! Arc radius. */
    double angle1;  /*! Start angle of arc or ellipse arc. */
    double angle2;  /*! End angle of arc or ellipse arc. */
    bool ccw;  /*! Counterclockwise flag for arc or ellipse arc. */
    double mx;  /*! Major axis end point (X). */
    double my;  /*! Major axis end point (Y). */
    double ratio;  /*! Axis ratio */
    unsigned int degree;  /*! Spline degree */
    bool rational;
    bool periodic;
    unsigned int nKnots;  /*! Number of knots. */
    unsigned int nControl;  /*! Number of control points. */
    unsigned int nFit;  /*! Number of fit points. */
    double startTangentX;
    double startTangentY;
    double endTangentX;
    double endTangentY;
};
//==============================================================================
/**
* @brief sst Dxf Hatch Loop Class
*
* storable hatch Loop record
*
* Used Type Definitions
* sstDxf03;HatchLoop;numEdges;II;6;0;sst Dxf Lib;sst HatchLoop;Number of edges in this loop
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf03TypHatchLoopCls // : public sstDxf03TypBaseCls
{
  public:
    sstDxf03TypHatchLoopCls();  // Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill hatch loop record from dxflib hatch loop <BR>
    * oSstDxfHatchLoop.ReadFromDL(poDLHatchLoop);
    *
    * @param poDLHatchLoop [in] dxflib hatch loop structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_HatchLoopData poDLHatchLoop);
    //==============================================================================
    /**
    * @brief // write Hatch loop record data to dxflib hatch loop <BR>
    * oSstDxfHatchLoop.WritToDL(poDLHatchLoop);
    *
    * @param poDLHatchLoop [out] dxflib hatch loop structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_HatchLoopData *poDLHatchLoop);
    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getRecordID() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setRecordID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    int getNumEdges() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setNumEdges(int value);
    //==============================================================================

private:
    dREC04RECNUMTYP dRecordID; /**< record id */
    int numEdges;               /**< numEdges */

};
//==============================================================================
/**
* @brief sst Dxf Polyline Class
*
* storable polyline record
*
* Used Type Definitions
* sstDxf03;Polyline;number;UI;6;0;sst Dxf Lib;sst Polyline;Number of vertices in this poly
* sstDxf03;Polyline;m;UI;6;0;sst Dxf Lib;sst Polyline;Number of vertices in m directi
* sstDxf03;Polyline;n;UI;6;0;sst Dxf Lib;sst Polyline;Number of vertices in n directi
* sstDxf03;Polyline;flags;II;6;0;sst Dxf Lib;sst Polyline;Flags
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf03TypPolylineCls : public sstDxf03TypBaseCls
{
  public:
    sstDxf03TypPolylineCls();  // Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill polyline record from dxflib polyline <BR>
    * oSstDxfPolyline.ReadFromDL(poDLPolyline);
    *
    * @param poDLPolyline [in] dxflib polyline structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_PolylineData poDLPolyline);
    //==============================================================================
    /**
    * @brief // write polyline record data to dxflib polyline <BR>
    * oSstDxfPolyline.WritToDL(poDLPolyline);
    *
    * @param poDLPolyline [out] dxflib polyline structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_PolylineData *poDLPolyline);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    unsigned int getNumber() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setNumber(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    unsigned int getM() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setM(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    unsigned int getN() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setN(unsigned int value);
    //==============================================================================
    /**
    * @brief // Get Layer ID <BR>
    * ulLayerID = oSstDxfLay.GetLayerID();
    *
    * @return unsigned long Layer ID
    */
    // ----------------------------------------------------------------------------
    int getFlags() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setFlags(int value);
    //==============================================================================

private:

    unsigned int number;  /*! Number of vertices in this polyline. */
    unsigned int m;  /*! Number of vertices in m direction if polyline is a polygon mesh. */
    unsigned int n;  /*! Number of vertices in n direction if polyline is a polygon mesh. */
    int flags;  /*! Flags */
};
//==============================================================================
/**
* @brief sst Trace
*
* More Comment
*
* Used Type Definitions
* sstDxf03;Trace;sx1;DD;12;4;sst Dxf Lib;sst Trace;sx1
* sstDxf03;Trace;sy1;DD;12;4;sst Dxf Lib;sst Trace;sy1
* sstDxf03;Trace;sz1;DD;12;4;sst Dxf Lib;sst Trace;sz1
* sstDxf03;Trace;sx2;DD;12;4;sst Dxf Lib;sst Trace;sx2
* sstDxf03;Trace;sy2;DD;12;4;sst Dxf Lib;sst Trace;sy2
* sstDxf03;Trace;sz2;DD;12;4;sst Dxf Lib;sst Trace;sz2
* sstDxf03;Trace;sx3;DD;12;4;sst Dxf Lib;sst Trace;sx3
* sstDxf03;Trace;sy3;DD;12;4;sst Dxf Lib;sst Trace;sy3
* sstDxf03;Trace;sz3;DD;12;4;sst Dxf Lib;sst Trace;sz3
* sstDxf03;Trace;sx4;DD;12;4;sst Dxf Lib;sst Trace;sx4
* sstDxf03;Trace;sy4;DD;12;4;sst Dxf Lib;sst Trace;sy4
* sstDxf03;Trace;sz4;DD;12;4;sst Dxf Lib;sst Trace;sz4
* sstDxf03;Trace;thickness;DD;12;4;sst Dxf Lib;sst Trace;thickness
*
* Changed: 21.03.18  Re.
*
* @ingroup sstDxf03Lib
*
* @author Re.
*
* @date 21.03.18
*/
// ----------------------------------------------------------------------------
class sstDxf03TypTraceCls : public sstDxf03TypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03TypTraceCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03TypTraceCls();// Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    * @param iKey
    * @param *sErrTxt
    * @param *ssstDxf03_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf03_Str);// Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    * @param iKey
    * @param *ssstDxf03_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey , std::string *ssstDxf03_Str);// Csv Write Function
    //==============================================================================
    /**
    * @brief // read Trace data from dxflib trace <BR>
    * oSstDxfTrace.ReadFromDL(poDLTrace);
    *
    * @param poDLTrace [in] dxflib trace structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_TraceData poDLTrace);
    //==============================================================================
    /**
    * @brief // write trace data to dxflib trace <BR>
    * oSstDxfTrace.WritToDL(poDLTrace);
    *
    * @param poDLTrace [out] dxflib trace structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_TraceData *poDLTrace);
    //==============================================================================
    double sx1;  /**< sx1 */
    double sy1;  /**< sy1 */
    double sz1;  /**< sz1 */
    double sx2;  /**< sx2 */
    double sy2;  /**< sy2 */
    double sz2;  /**< sz2 */
    double sx3;  /**< sx3 */
    double sy3;  /**< sy3 */
    double sz3;  /**< sz3 */
    double sx4;  /**< sx4 */
    double sy4;  /**< sy4 */
    double sz4;  /**< sz4 */
    double thickness;  /**< thickness */
  private:
};

//==============================================================================
/**
* @brief sst Dxf Vertex Class
*
* storable vertex record
*
* Used Type Definitions
* sstDxf03;Vertex;x;DD;12;4;sst Dxf Lib;sst Vertex;X Coordinate of the vertex
* sstDxf03;Vertex;y;DD;12;4;sst Dxf Lib;sst Vertex;Y Coordinate of the vertex
* sstDxf03;Vertex;z;DD;12;4;sst Dxf Lib;sst Vertex;Z Coordinate of the vertex
* sstDxf03;Vertex;bulge;DD;12;4;sst Dxf Lib;sst Vertex;Bulge of vertex
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf03TypVertexCls // : public sstDxf03TypBaseCls
{
  public:
    sstDxf03TypVertexCls();  // Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfInsert.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // fill vertex record from dxflib vertex <BR>
    * oSstDxfVertex.ReadFromDL(poDLVertex);
    *
    * @param poDLVertex [in] dxflib Vertex structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_VertexData poDLVertex);
    //==============================================================================
    /**
    * @brief // write vertex record data to dxflib vertex <BR>
    * oSstDxfVertex.WritToDL(poDLVertex);
    *
    * @param poDLVertex [out] dxflib vertex structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_VertexData *poDLVertex);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getRecordID() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setRecordID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getParentID() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setParentID(const dREC04RECNUMTYP &value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    RS2::EntityType getEntityType() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setEntityType(const RS2::EntityType &value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    double getX() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setX(double value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    double getY() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setY(double value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    double getZ() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setZ(double value);
    //==============================================================================
    /**
    * @brief // Get Record ID  <BR>
    *
    * @return unsigned long Record ID
    */
    // ----------------------------------------------------------------------------
    double getBulge() const;
    //==============================================================================
    /**
    * @brief // Set Record ID  <BR>
    *
    * @param value [in] Record ID
    */
    // ----------------------------------------------------------------------------
    void setBulge(double value);

private:
    dREC04RECNUMTYP dRecordID; /**< ID of vertex */
    dREC04RECNUMTYP dParentID; /**< ID of parent object */
    RS2::EntityType eEntityType;     /**< Polyline and so on ... */
    double x;  /*! X Coordinate of the vertex. */
    double y;  /*! Y Coordinate of the vertex. */
    double z;  /*! Z Coordinate of the vertex. */
    double bulge;  /*! Bulge of vertex. (The tangent of 1/4 of the arc angle or 0 for lines) */
};
//==============================================================================
/**
* @brief sst Dxf Layer Class
*
* template for sst base class <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf03TypLayCls : public sstDxf03TypBaseCls
{
  public:   // Public functions
     sstDxf03TypLayCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Set Layer name <BR>
     * oSstDxfLay.setName(iKey)
     *
     * @param cName [in] Set Name
     */
     // ----------------------------------------------------------------------------
     void setName(const char* cName);
     //==============================================================================
     /**
     * @brief // Get Layer Name <BR>
     * oSstDxfLay.getName(iKey)
     *
     * @return char Name
     */
     // ----------------------------------------------------------------------------
     char* getName();
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @return int flags
     */
     // ----------------------------------------------------------------------------
     int getFlags() const;
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @param value [in] Flags
     */
     // ----------------------------------------------------------------------------
     void setFlags(int value);
     //==============================================================================
     /**
     * @brief // Set Test Data <BR>
     * iStat= oSstDxfLay.SetTestData(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     int SetTestData(int iKey);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.ReadFromDL(poDLArc);
     *
     * @param poDlLay [in] dxflib Layer structure
     */
     void ReadFromDL(const DL_LayerData poDlLay);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.WritToDL(poDLArc);
     *
     * @param poDlLay [out] dxflib layer structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     void WritToDL(DL_LayerData *poDlLay);
     //==============================================================================
     /**
     * @brief // Get Layer ID <BR>
     * ulLayerID = oSstDxfLay.GetLayerID();
     *
     * @return unsigned long Layer ID
     */
     // ----------------------------------------------------------------------------
     unsigned long getLayerID() const;
     //==============================================================================
     /**
     * @brief // Set Layer ID <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @param value [in] Layer ID
     */
     // ----------------------------------------------------------------------------
     void setLayerID(unsigned long value);
     //==============================================================================
     /**
     * @brief // Get Size of Layer Name <BR>
     * iSizeNam = oSstDxfLay.GetSizeName();
     *
     * @return int size of name
     */
     // ----------------------------------------------------------------------------
     int getSizeName() const;
     //==============================================================================

  private:  // Private functions
    unsigned long ulLayerID;
    int flags;               /**< Layer flags. (1 = frozen, 2 = frozen by default, 4 = locked) */
    char Nam[dSSTDXF03LAYERNAMELEN]; /**< Layer Name */

};
//==============================================================================
/**
* @brief sst Dxf Block Class
*
* template for sst base class <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf03TypBlkCls : public sstDxf03TypBaseCls
{
  public:   // Public functions
     sstDxf03TypBlkCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @param cName [in] For the moment 0
     */
     // ----------------------------------------------------------------------------
     void setName(const char* cName);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @return char Name
     */
     // ----------------------------------------------------------------------------
     char* getName();
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @return int flags
     */
     // ----------------------------------------------------------------------------
     int getFlags() const;
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @param value [in] Flags
     */
     // ----------------------------------------------------------------------------
     void setFlags(int value);
     //==============================================================================
     /**
     * @brief // Set Test Data <BR>
     * iStat= oSstDxfBlk.SetTestData(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     int SetTestData(int iKey);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.ReadFromDL(poDlBlk);
     *
     * @param poDlBlk [in] dxflib arc structure
     */
     void ReadFromDL(const DL_BlockData poDlBlk);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.WritToDL(poDlBlk);
     *
     * @param poDlBlk [out] dxflib arc structure
     */
     void WritToDL(DL_BlockData *poDlBlk);
     //==============================================================================
     /**
     * @brief // Get Block ID <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @return unsigned long ulBlockID
     */
     // ----------------------------------------------------------------------------
     unsigned long getBlockID() const;
     //==============================================================================
     /**
     * @brief // Set Block ID <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @param value [in] Block ID
     */
     // ----------------------------------------------------------------------------
     void setBlockID(unsigned long value);
     //==============================================================================
     /**
     * @brief // Update Mbr with coordinates <BR>
     * iStat = oSstDxfBlk.updateMbr(iKey)
     *
     * @param iKey [in] Key
     * @param oMbr [in] Minimum bounding rectangle
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int updateMbr(int iKey, sstMath01Mbr2Cls oMbr);
     //==============================================================================
     /**
     * @brief // Get Minimum Border Rectangle <BR>
     * oMbr = oSstDxfBlk.getMbr()
     *
     * @return Minimum Border Rectangle
     */
     // ----------------------------------------------------------------------------
     sstMath01Mbr2Cls getMbr() const;
     //==============================================================================
     char Nam[dSSTDXF03BLOCKNAMELEN];  /**< Block Name public because of sorting */
  private:  // Private functions
     unsigned long ulBlockID;  /**< intern Block ID */
     int  flags;               /**< Block Flags */
     sstMath01Mbr2Cls oMbr;    /**< Minimum border rectangle */
};
//==============================================================================
/**
* @brief Base Class for sst DXF function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncBaseCls: public sstRec04Cls
{
  public:
  //==============================================================================
  /**
  * @brief // constructor with record size <BR>
  *
  * @param iSize [in] Record size
  */
  // ----------------------------------------------------------------------------
    sstDxf03FncBaseCls(dREC04RECSIZTYP iSize);  // Constructor
    //==============================================================================
    /**
    * @brief // read base attribute data from csv string to base object <BR>
    * iStat = oDxfFncBase1.Csv_BaseRead( iKey, oErrStr, oCsvArcStr, oArc);
    *
    * "RecordNo";"LayerNo";"BlockNo"
    *
    * @param iKey         [in]  For the moment 0
    * @param oErrStr      [out] string where interpret error occors
    * @param oCsvBaseStr  [in]  Csv Arc string
    * @param oAttributes  [out] return base dxf attribute object
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_BaseRead1(int iKey, std::string *oErrStr, std::string *oCsvBaseStr, sstDxf03TypBaseCls *oAttributes);
    //==============================================================================
    /**
    * @brief // // write base attribute data from base object to csv string <BR>
    * iStat = oDxfFncBase.Csv_BaseWrite1( iKey, oAttributes, ssstDxfLib_Str);
    *
    * "RecordNo";"LayerNo";"BlockNo"
    *
    * @param iKey           [in] For the moment 0
    * @param oAttributes   [in] base dxf attributes
    * @param ssstDxfLib_Str [out] csv string with base dxf attributes
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_BaseWrite1(int iKey, sstDxf03TypBaseCls oAttributes, std::string *ssstDxfLib_Str);
    //==============================================================================
    /**
    * @brief // write base attributes titel row to csv file <BR>
    * iStat = oDxfFncBase.Csv_BaseHeader1 ( 0, &oCsvStr)
    *
    * "RecordNo";"LayerNo";"BlockNo"
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_BaseHeader1(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // read base attribute data from csv string to base object <BR>
    * iStat = oDxfFncBase.Csv_BaseRead2( iKey, oErrStr, oCsvArcStr, oArc);
    *
    * "LineTypeID";"Color";"Color24";"Width";"Handle"
    *
    * @param iKey         [in]  For the moment 0
    * @param oErrStr      [out] string where interpret error occors
    * @param oCsvBaseStr  [in]  Csv Arc string
    * @param oAttributes  [out] return base dxf attribute object
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_BaseRead2(int iKey, std::string *oErrStr, std::string *oCsvBaseStr, sstDxf03TypBaseCls *oAttributes);
    //==============================================================================
    /**
    * @brief // // write base attribute data from base object to csv string <BR>
    * iStat = oDxfFncBase.Csv_BaseWrite2( iKey, oAttributes, ssstDxfLib_Str);
    *
    * "LineTypeID";"Color";"Color24";"Width";"Handle"
    *
    * @param iKey           [in] For the moment 0
    * @param oAttributes   [in] base dxf attributes
    * @param ssstDxfLib_Str [out] csv string with base dxf attributes
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_BaseWrite2(int iKey, sstDxf03TypBaseCls oAttributes, std::string *ssstDxfLib_Str);
    //==============================================================================
    /**
    * @brief // write base attribtes titel row to csv file <BR>
    * iStat = oDxfFncBase.Csv_BaseHeader2 ( 0, &oCsvStr)
    *
    * "LineTypeID";"Color";"Color24";"Width";"Handle"
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_BaseHeader2(int iKey, std::string *oCsvStr);

    sstStr01Cls oCsvRow;   /**< Csv String Convert object */
    // char cDbleFrmt[10];
  private:
};
//==============================================================================
/**
* @brief LineType table class
*
* LineType table class <BR>
*
* Changed: 10.06.16  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 10.06.16
*/
// ----------------------------------------------------------------------------
class sstDxf03FncLTypeCls : public sstDxf03FncBaseCls
{
  public:   // Public functions
     sstDxf03FncLTypeCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // write new record to table if unique LType name <BR>
     * iStat = oLTypeTab.WriteNewUnique(iKey);
     *
     * @param iKey      [in] For the moment 0
     * @param oLTypeRec [in] LType Record
     * @param dLTypeRecNo [out] new LType Record number
     *
     * @return Errorstate
     *
     * @retval   = 1: New record written
     * @retval   = 0: name already in table, not written
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteNewUnique(int iKey,sstDxf03TypLTypeCls oLTypeRec, dREC04RECNUMTYP *dLTypeRecNo);
     //==============================================================================
     /**
     * @brief // Read line type object from string row <BR>
     * iStat = oSstFncLType.CsvRead ( iKey, oErrStr, oRowStr, oSstLay);
     *
     * @param iKey     [in]  For the moment 0
     * @param oErrStr  [out] Read Error at string part
     * @param oRowStr  [in]  read row
     * @param oSstLType  [out] result line type object
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_Read(int                iKey,
                  std::string       *oErrStr,
                  std::string       *oRowStr,
                  sstDxf03TypLTypeCls *oSstLType);  // Csv Read Function
     //==============================================================================
     /**
     * @brief // Write linr type object to row string <BR>
     * iStat = oSstFncLType.Csv_Write ( iKey, oSstLType, oRowStr);
     *
     * @param iKey    [in] For the moment 0
     * @param oSstLType [in] Layer object
     * @param sRowStr [out] Result Row string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_Write(int                iKey,
                   sstDxf03TypLTypeCls *oSstLType,
                   std::string       *sRowStr);
     //==============================================================================
     /**
     * @brief // write Layer titel row to csv file <BR>
     * iStat = oSstFncLay.Csv_WriteHeader ( 0, &oCsvStr)
     *
     * @param iKey    [in]  For the moment 0
     * @param oCsvStr [out] return string titel row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_WriteHeader(int iKey, std::string *oCsvStr);
     //==============================================================================
     /**
     * @brief // Return Linetype name sorting key <BR>
     * poNameSortKey = oSstFncLType.GetNameSortKey();
     *
     * @return LType Name sorting key
     */
     // ----------------------------------------------------------------------------
     sstRec04TreeKeyCls* getNameSortKey();
     //==============================================================================
     /**
     * @brief // Read whole linetype csv file into sst_rec_mem <BR>
     * iStat = oSstFncLType.ReadCsvFile ( iKey, oFilNam);
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name to import to rec mem
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: Open File Error
     * @retval   = -3: General read error
     * @retval   = -4: Record format read Error
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadCsvFile(int iKey, std::string oFilNam);
     //==============================================================================
     /**
     * @brief // write whole linetype data from table to csv file  <BR>
     * iStat = oDxfFncLType.WriteCsvFile ( iKey, oDxfFilNam);
     *
     * @param iKey       [in] For the moment 0
     * @param oDxfFilNam [in] File name to export to csv file
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     */
     // ----------------------------------------------------------------------------
     int WriteCsvFile(int iKey, std::string oDxfFilNam);
     //==============================================================================


// ----------------------------------------------------------------------------
  private:  // Private functions
     sstRec04TreeKeyCls oLTypeTree; /**< sort tree for linetype names in table */
};
//==============================================================================
/**
* @brief Definition Class sstDxf03FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncArcCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncArcCls();  // Constructor
    //==============================================================================
    /**
    * @brief // read arc data from csv string to arc object <BR>
    * iStat = oDxfFncArc.Csv_Read( iKey, oErrStr, oCsvArcStr, oArc);
    *
    * @param iKey       [in]  For the moment 0
    * @param oErrStr    [out] string where interpret error occors
    * @param oCsvArcStr [in]  Csv Arc string
    * @param oArc       [out] return arc object
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                iKey,
                 std::string       *oErrStr,
                 std::string       *oCsvArcStr,
                 sstDxf03TypArcCls *oArc);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncArc.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param osstDxf03TypArcCls [in] For the moment 0
    * @param ssstDxfLib_Str [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int iKey,
                  sstDxf03TypArcCls *osstDxf03TypArcCls,
                  std::string *ssstDxfLib_Str);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oDxfFncArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oDxfFncArc.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole arc data from table to csv file  <BR>
    * iStat = oSstFncArc.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
//==============================================================================
/**
* @brief Definition Class sstDxf03FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncTraceCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncTraceCls();  // Constructor
    //==============================================================================
    /**
    * @brief // read Trace data from csv string to Trace object <BR>
    * iStat = oDxfFncTrace.Csv_Read( iKey, oErrStr, oCsvTraceStr, oTrace);
    *
    * @param iKey       [in]  For the moment 0
    * @param oErrStr    [out] string where interpret error occors
    * @param oCsvTraceStr [in]  Csv Trace string
    * @param oTrace       [out] return Trace object
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                iKey,
                 std::string       *oErrStr,
                 std::string       *oCsvTraceStr,
                 sstDxf03TypTraceCls *oTrace);
    //==============================================================================
    /**
    * @brief // Write object to string <BR>
    * iStat = oDxfFncTrace.Csv_Write(iKey, oTrace, &oTraceStr);
    *
    * @param iKey [in] For the moment 0
    * @param osstDxf03TypTraceCls [in] Trace object
    * @param ssstDxfLib_Str [out] Trace String
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int iKey,
                  sstDxf03TypTraceCls *osstDxf03TypTraceCls,
                  std::string *ssstDxfLib_Str);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oDxfFncArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oDxfFncArc.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole arc data from table to csv file  <BR>
    * iStat = oSstFncArc.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Definition Class sstDxf03FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncInsertCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncInsertCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oCsvInsert.Csv_Read(iKey, oErrStr, oString, oDxfInsert);
    *
    * @param iKey [in] For the moment 0
    * @param sErrTxt [in] For the moment 0
    * @param ssstDxfLib_Str [in] For the moment 0
    * @param osstDxf03TypArcCls [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int iKey,
                 std::string *sErrTxt,
                 std::string *ssstDxfLib_Str,
                 sstDxf03TypInsertCls *osstDxf03TypArcCls);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oCsvArc.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param osstDxf03TypArcCls [in] For the moment 0
    * @param ssstDxfLib_Str [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int iKey,
                  sstDxf03TypInsertCls *osstDxf03TypArcCls,
                  std::string *ssstDxfLib_Str);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole insert data from table to csv file  <BR>
    * iStat = oDxfFncInsert.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncHatchCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncHatchCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncHatch.Csv_Read(iKey, oErrStr, oCsvHatchStr, oHatch);
    *
    * @param iKey         [in] For the moment 0
    * @param oErrStr      [in] For the moment 0
    * @param oCsvHatchStr [in] For the moment 0
    * @param oHatch       [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                  iKey,
                 std::string         *oErrStr,
                 std::string         *oCsvHatchStr,
                 sstDxf03TypHatchCls *oHatch);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncHatch.Csv_Write ( iKey, oHatch, oCsvHatchStr);
    *
    * @param iKey         [in] For the moment 0
    * @param oHatch       [in] For the moment 0
    * @param oCsvHatchStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                  iKey,
                  sstDxf03TypHatchCls *oHatch,
                  std::string         *oCsvHatchStr);
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncHatchEdgeCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncHatchEdgeCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncHEdge.Csv_Read(iKey, oErrStr, oCsvHEdgeStr, oHatchEdge);
    *
    * @param iKey         [in] For the moment 0
    * @param oErrStr      [in] For the moment 0
    * @param oCsvHEdgeStr [in] For the moment 0
    * @param oHatchEdge   [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                      iKey,
                 std::string             *oErrStr,
                 std::string             *oCsvHEdgeStr,
                 sstDxf03TypHatchEdgeCls *oHatchEdge);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncHEdge.Csv_Write ( iKey, oHatchEdge, oCsvHEdgeStr);
    *
    * @param iKey         [in] For the moment 0
    * @param oHatchEdge   [in] For the moment 0
    * @param oCsvHEdgeStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                      iKey,
                  sstDxf03TypHatchEdgeCls *oHatchEdge,
                  std::string             *oCsvHEdgeStr);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncHatchLoopCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncHatchLoopCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncHLoop.Csv_Read(iKey, oErrStr, oCsvHLoopStr, oHatchLoop);
    *
    * @param iKey         [in] For the moment 0
    * @param oErrStr      [in] For the moment 0
    * @param oCsvHLoopStr [in] For the moment 0
    * @param oHatchLoop   [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                      iKey,
                 std::string             *oErrStr,
                 std::string             *oCsvHLoopStr,
                 sstDxf03TypHatchLoopCls *oHatchLoop);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncHLoop.Csv_Write ( iKey, oHatchLoop, oCsvHLoopStr);
    *
    * @param iKey         [in] For the moment 0
    * @param oHatchLoop   [in] For the moment 0
    * @param oCsvHLoopStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                      iKey,
                  sstDxf03TypHatchLoopCls *oHatchLoop,
                  std::string             *oCsvHLoopStr);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncPolylineCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncPolylineCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncPLine.Csv_Read(iKey, oErrStr, oCsvPLineStr, oPolyline);
    *
    * @param iKey         [in] For the moment 0
    * @param oErrStr      [in] For the moment 0
    * @param oCsvPLineStr [in] For the moment 0
    * @param oPolyline    [out] Polyline
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                     iKey,
                 std::string            *oErrStr,
                 std::string            *oCsvPLineStr,
                 sstDxf03TypPolylineCls *oPolyline);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oDxfFncPline.Csv_Write ( iKey, oPolyline, oCsvPlineStr);
    *
    * @param iKey         [in] For the moment 0
    * @param oPolyline    [in] For the moment 0
    * @param oCsvPLineStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                     iKey,
                  sstDxf03TypPolylineCls *oPolyline,
                  std::string            *oCsvPLineStr);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Hatch function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncVertexCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncVertexCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Csv Read <BR>
    * iStat = oDxfFncVertex.Csv_Read(iKey, oErrStr, oCsvVertexStr, oVertex);
    *
    * @param iKey          [in] For the moment 0
    * @param oErrStr       [in] For the moment 0
    * @param oCsvVertexStr [in] For the moment 0
    * @param oVertex       [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                   iKey,
                 std::string          *oErrStr,
                 std::string          *oCsvVertexStr,
                 sstDxf03TypVertexCls *oVertex);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // write Vertex object to csv string <BR>
    * iStat = oDxfFncVertex.Csv_Write ( iKey, oVertex, oCsvVertexStr);
    *
    * @param iKey          [in] For the moment 0
    * @param oVertex       [in] For the moment 0
    * @param oCsvVertexStr [out] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                   iKey,
                  sstDxf03TypVertexCls *oVertex,
                  std::string          *oCsvVertexStr);
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Layer table class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncLayCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncLayCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Return Layer name sorting key <BR>
    * poNameSortKey = oSstFncLay.Func_1();
    *
    * @return Layer Name sorting key
    */
    // ----------------------------------------------------------------------------
    sstRec04TreeKeyCls* getNameSortKey();
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole layer data from table to csv file  <BR>
    * iStat = oDxfFncLayer.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================
    /**
    * @brief // Read layer object from string row <BR>
    * iStat = oSstFncLay.CsvRead ( iKey, oErrStr, oRowStr, oSstLay);
    *
    * @param iKey     [in]  For the moment 0
    * @param oErrStr  [out] Read Error at string part
    * @param oRowStr  [in]  read row
    * @param oSstLay  [out] result layer object
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                iKey,
                 std::string       *oErrStr,
                 std::string       *oRowStr,
                 sstDxf03TypLayCls *oSstLay);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // Write layer object to row string <BR>
    * iStat = oSstFncLay.Csv_Write ( iKey, oSstLay, oRowStr);
    *
    * @param iKey    [in] For the moment 0
    * @param oSstLay [in] Layer object
    * @param sRowStr [out] Result Row string
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                iKey,
                  sstDxf03TypLayCls *oSstLay,
                  std::string       *sRowStr);
    //==============================================================================
    /**
    * @brief // write Layer titel row to csv file <BR>
    * iStat = oSstFncLay.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Update existing layer or write new into table <BR>
    * iStat = oSstFncLay.UpdateWriteNew ( 0, oLayRec, &dLayRecNo);
    *
    * @param iKey      [in]  For the moment 0
    * @param oLayRec   [in]  Layer Record
    * @param dLayRecNo [out] existing or new record number
    *
    * @return function state
    *
    * @retval   =  1: New layer
    * @retval   =  0: Existing layer
    * @retval   = -1: Wrong Key
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int UpdateWriteNew(int iKey, sstDxf03TypLayCls oLayRec, dREC04RECNUMTYP *dLayRecNo);
    //==============================================================================
  private:
    sstRec04TreeKeyCls oLayerTree; /**< sort tree for layers names in table */

};
//==============================================================================
/**
* @brief Definition Class sstDxf03FncBlkCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncBlkCls : public sstDxf03FncBaseCls
{
  public:
    sstDxf03FncBlkCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Return Block name sorting key <BR>
    * poNameSortKey = oSstFncBlk.Func_1();
    *
    * @return Block Name sorting key
    */
    // ----------------------------------------------------------------------------
    sstRec04TreeKeyCls* getNameSortKey();
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * oTestBase.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param sErrTxt [in] For the moment 0
    * @param sSstDxfLib_Str [in] For the moment 0
    * @param oSstDxf01TypBlk [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                iKey,
                 std::string       *sErrTxt,
                 std::string       *sSstDxfLib_Str,
                 sstDxf03TypBlkCls *oSstDxf01TypBlk);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * oTestBase.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param oSstDxf01TypBlk [in] For the moment 0
    * @param sSstDxfLib_Str [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                iKey,
                  sstDxf03TypBlkCls *oSstDxf01TypBlk,
                  std::string       *sSstDxfLib_Str);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oSstFncLay.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write block layer data from table to csv file  <BR>
    * iStat = oDxfFncBlock.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================
    /**
    * @brief // Get Minimum Border Rectangle of Model Space / Section entities <BR>
    * oMbr = oDxfFncBlock.getMbrModel()
    *
    * @return Minimum Border Rectangle
    */
    // ----------------------------------------------------------------------------
    sstMath01Mbr2Cls getMbrModel();
    //==============================================================================
    /**
    * @brief // Update Mbr of Model with next object Mbr <BR>
    * iStat = oDxfFncBlock.updateMbrModel(iKey, oMbr);
    *
    * @param iKey [in] For the moment 0
    * @param oMbr [in] Minimum Bounding Rectangle
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int updateMbrModel(int iKey, sstMath01Mbr2Cls oMbr);
    //==============================================================================
    /**
    * @brief // Update Mbr of block with next object Mbr <BR>
    * iStat = oDxfFncBlock.updateMbrBlock(iKey, dBlkNo, oMbr);
    *
    * @param iKey   [in] For the moment 0
    * @param dBlkNo [in] Block number
    * @param oMbr   [in] Minimum Bounding Rectangle
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int updateMbrBlock(int iKey,   dREC04RECNUMTYP dBlkNo, sstMath01Mbr2Cls oMbr);
    //==============================================================================
    /**
    * @brief // return Block Model Record number <BR>
    * dRecordNo = oDxfFncBlock.getBlockMdlRecNo();
    *
    * @return Record number
    */
    // ----------------------------------------------------------------------------
    dREC04RECNUMTYP getBlockMdlRecNo() const;
    //==============================================================================
    /**
    * @brief // Set record number <BR>
    * oDxfFncBlock.setBlockMdlRecNo(dValue);
    *
    * @param dValue [in] record number
    */
    // ----------------------------------------------------------------------------
    void setBlockMdlRecNo(dREC04RECNUMTYP dValue);
    //==============================================================================

private:
    sstRec04TreeKeyCls oBlockTree; /**< sort tree for block names in table */
    dREC04RECNUMTYP dBlockMdlRecNo;  /**< actual record number of model space block (section entities)  */
};

//==============================================================================
/**
* @brief dxf main record for storing in record memory
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf03TypMainCls
{
  public:   // Public functions
     sstDxf03TypMainCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getMainID() const;
     //==============================================================================
     /**
     * @brief // Set record number in csv file <BR>
     * oDxfMainRec.SetMainID(dValue);
     *
     * @param dValue [in] main record number
     */
     // ----------------------------------------------------------------------------
     void setMainID(const dREC04RECNUMTYP &dValue);
     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     std::string getSectString() const;
     //==============================================================================
     /**
     * @brief // Set section string B or L in csv file <BR>
     * oDxfMainRec.SetSectString(oSectString);
     *
     * @param oSectString [in] section string B or L
     */
     // ----------------------------------------------------------------------------
     void setSectString(const std::string &oSectString);

     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getLayBlockID() const;
     //==============================================================================
     /**
     * @brief // Set record number of block or layer in csv file <BR>
     * oDxfMainRec.SetMainID(dValue);
     *
     * @param dValue [in] main record number
     */
     // ----------------------------------------------------------------------------
     void setLayBlockID(const dREC04RECNUMTYP &dValue);
     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     RS2::EntityType getEntityType() const;
     //==============================================================================
     /**
     * @brief // Set entity type in csv file <BR>
     * oDxfMainRec.SetMainID(dValue);
     *
     * @param eValue [in] entity type
     */
     // ----------------------------------------------------------------------------
     void setEntityType(const RS2::EntityType &eValue);
     //==============================================================================
     /**
     * @brief // return record number in csv file <BR>
     * dRecordNo = oDxfMainRec.getMainID();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getTypeID() const;
     //==============================================================================
     /**
     * @brief // Set record number in csv file <BR>
     * oDxfMainRec.SetMainID(dValue);
     *
     * @param dValue [in] main record number
     */
     // ----------------------------------------------------------------------------
     void setTypeID(const dREC04RECNUMTYP &dValue);
     //==============================================================================
     /**
     * @brief // Get Minimum Bounding Rectangle <BR>
     * oMinBndRct = oDxfMainRec.getMbr();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     sstMath01Mbr2Cls getMbr() const;
     //==============================================================================
     /**
     * @brief // Set minimum bounding rectangle <BR>
     * oDxfMainRec.SetMbr( oMbr);
     *
     * @param oMbr [in] Minimum bounding rectangle
     */
     // ----------------------------------------------------------------------------
     void setMbr(const sstMath01Mbr2Cls oMbr);
     //==============================================================================

private:  // Private functions
  dREC04RECNUMTYP   dMainID;          /**< Record number in this main file */
  char              cSectionType[2];  /**< L or B */
  dREC04RECNUMTYP   dLayBlockID;      /**< Record number in Layer or block file */
  RS2::EntityType   eEntityType;      /**< ARC. CIRCE, LINE, VERTEX and so on ... */
  dREC04RECNUMTYP   dTypeID;          /**< Record number in type file */
  sstMath01Mbr2Cls  oMinBndRct;       /**< Minimum Bounding Rectangle */
};
//==============================================================================
/**
* @brief Function class for dxf main record
*
* number; Section; numSect;  Type; numType;  <BR>
*      1;       B;    567;    Arc;     234;  <BR>
*
*
* Changed: 08.07.15  Re.
*
* @ingroup sstTemplateIntLib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf03FncMainCls : public sstDxf03FncBaseCls
{
  public:   // Public functions
     sstDxf03FncMainCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * iStat = oMainFnc.Func_1(iKey)
     *
     * @param iKey [in] For the moment 0
     * @param sErrTxt [in] For the moment 0
     * @param ssstDxfLib_Str [in] For the moment 0
     * @param osstDxf03TypMainCls [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_Read(int iKey,
                  std::string *sErrTxt,
                  std::string *ssstDxfLib_Str,
                  sstDxf03TypMainCls *osstDxf03TypMainCls);  // Csv Read Function
     //==============================================================================
     /**
     * @brief // convert dxf main record into csv string <BR>
     * iStat = oMainFnc.Csv_Write(iKey, oMainRec, oMainStr);
     *
     * @param iKey        [in] For the moment 0
     * @param oMainRec    [in] sst dxf main record
     * @param oMainCsvStr [out] result string
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_Write(int                 iKey,
                   sstDxf03TypMainCls *oMainRec,
                   std::string        *oMainCsvStr);
     //==============================================================================
     /**
     * @brief // write ARC titel row to csv file <BR>
     * iStat = oMainFnc.Csv_WriteHeader ( 0, &oCsvStr)
     *
     * @param iKey    [in]  For the moment 0
     * @param oCsvStr [out] return string titel row
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Csv_WriteHeader(int iKey, std::string *oCsvStr);
     //==============================================================================
     /**
     * @brief // Read whole layer csv file into sst_rec_mem <BR>
     * iStat = oMainFnc.ReadCsvFile ( iKey, oFilNam);
     *
     * @param iKey    [in] For the moment 0
     * @param oFilNam [in] File name to import to rec mem
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     * @retval   = -2: Open File Error
     * @retval   = -3: General read error
     * @retval   = -4: Record format read Error
     * @retval   <  0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadCsvFile(int iKey, std::string oFilNam);
     //==============================================================================
     /**
     * @brief // write whole main data from table to csv file  <BR>
     * iStat = oMainFnc.WriteCsvFile ( iKey, oDxfFilNam);
     *
     * @param iKey       [in] For the moment 0
     * @param oDxfFilNam [in] File name to export to csv file
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     */
     // ----------------------------------------------------------------------------
     int WriteCsvFile(int iKey, std::string oDxfFilNam);
     //==============================================================================
     /**
     * @brief // Update Mbr  <BR>
     * iStat = oMainFnc.UpdateMbr ( iKey, oDxfFilNam);
     *
     * @param iKey   [in] For the moment 0
     * @param oMbr   [in] Update Mbr with next Data
     *
     * @return Errorstate
     *
     * @retval   =  0: OK
     * @retval   = -1: Wrong Key
     */
     // ----------------------------------------------------------------------------
     int UpdateMbr (int iKey, sstMath01Mbr2Cls oMbr);
     //==============================================================================
     /**
     * @brief // Get Minimum Bounding Rectangle <BR>
     * oMinBndRct = oDxfMainRec.getMbr();
     *
     * @return Record number of main record
     */
     // ----------------------------------------------------------------------------
     sstMath01Mbr2Cls getMbr() const;
     //==============================================================================
private:  // Private functions
  sstMath01Mbr2Cls oMbr; /**< Minimum Border Rectangle */
};
//==============================================================================

//==============================================================================
/**
* @brief Definition sstDxfBase_Cls
*
* More Comment
*
* Changed: 19.02.10  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class sstDxfBase_Cls
{
  public:   // Öffentliche Funktionen
     sstDxfBase_Cls();  // Konstruktor
    // ~sstDxfBase_Cls();  // Destruktor
     //==============================================================================
     /**
     * @brief GetName
     */
     // ----------------------------------------------------------------------------
     void GetName();
     //==============================================================================
     /**
     * @brief SetName
     */
     // ----------------------------------------------------------------------------
     void SetName();
     //==============================================================================
     /**
     * @brief GetID
     *
     * @param ulLocID [out] ulLocID
     */
     // ----------------------------------------------------------------------------
     void GetId( unsigned long *ulLocID);
     //==============================================================================
     /**
     * @brief SetID
     *
     * @param ulLocID [in] ulLocID
     */
     // ----------------------------------------------------------------------------
     void SetId( unsigned long ulLocID);
     //==============================================================================
     /**
     * @brief GetName
     *
     * @param cLocName [out] cLocName
     * @param uiNamLen [out] uiNamLen
     */
     // ----------------------------------------------------------------------------
     void GetName( char *cLocName, unsigned int uiNamLen);
     //==============================================================================
     /**
     * @brief SetName
     *
     * @param cLocName [in] cLocName
     */
     // ----------------------------------------------------------------------------
     void SetName( char *cLocName);
     //==============================================================================
     /**
     * @brief UpdateMinMax
     *
     * @param iKey    [in] For the moment 0
     * @param oVertex [in] oVertex
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int UpdateMinMax (int           iKey,
                       DL_VertexData oVertex);
     //==============================================================================
     /**
     * @brief ResetMinMax
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ResetMinMax (int    iKey);


  private:  // Private Funktionen
  char cName[33];  /**< Name of Dxf Element */
  unsigned long ulID;  /**< Identifier of Dxf Element */
};
//==============================================================================
/**
* @brief Definition sstDxfPolylineCls
*
* dxf polyline with vertex memory
*
* Changed: 07.06.13  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 07.06.13
*/
// ----------------------------------------------------------------------------
class sstDxfPolylineCls : public sstDxfBase_Cls
{
  public:   // Öffentliche Funktionen
     // Constructor
  //==============================================================================
  /**
  * @brief Constructor
  *
  * iStat = Blanko ( iKey);
  *
  * More Comment
  *
  * Changed: 16.02.10  Re.
  *
  * @ingroup sst_dxf_lib
  *
  * @author Re.
  *
  * @date 16.02.10
  */
  //------------------------------------------------------------------------------
     sstDxfPolylineCls(): myTestpoly(0,0,0,0)
     {
       // int iStat = 0;
       lActVertex = 0;
       // Heap-Objekt öffnen und Heap anlegen.
       // SST_HPO_Auf_c ( 0, &sVertexHeap, 10, sizeof(DL_VertexData));

       // Initialize Min-Max
       // iStat = Mia_3Ini_c ( 0, &sMiMa);

     }
     // Destructor
     //==============================================================================
     /**
     * @brief Destructor
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     ~sstDxfPolylineCls()
     {
       // int iStat = 0;
       // Heap-Objekt beenden und Heap an BS zurückgeben.
       // SST_HPO_Zu_c ( 0, &sVertexHeap);

     }
     //==============================================================================
     /**
     * @brief AddVertex
     *
     * iStat = Blanko ( iKey);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey    [in] For the moment 0
     * @param oVertex [in] vertex record
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int AddVertex(int            iKey,
                   DL_VertexData *oVertex);
     //==============================================================================
     /**
     * @brief Get next Vertex from Object
     *
     * iStat = GetVertex( iKey, *oVertex);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey: [in] For the moment 0
     * @param oVertex: [out] Get next Vertex
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int GetVertex(int            iKey,
                   DL_VertexData *oVertex);
     //==============================================================================
     /**
     * @brief Reset Vertex Getter
     *
     * iStat = Reset( iKey);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey: [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int ResetGet(int iKey);
     //==============================================================================
     /**
     * @brief Clear all Vertex from Polyline memory
     *
     * iStat = ClearMemory( iKey);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey: [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int ClearMemory(int iKey);
     //==============================================================================
     /**
     * @brief Clear all Vertex from Polyline memory
     *
     * iStat = ClearMemory( iKey);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey       [in] For the moment 0
     * @param lNumVertex [in out] lNumVertex
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int GetNumVertex(int iKey, unsigned long *lNumVertex);
     //==============================================================================
     /**
     * @brief Write PolyLine to Dxf File
     *
     * iStat = WrtPLine2File ( iKey, **dxf, **dw);
     *
     * More Comment
     *
     * Changed: 16.02.10  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey [in] For the moment 0
     * @param dxf  [in out]
     * @param dw   [in out]
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 16.02.10
     */
     //------------------------------------------------------------------------------
     int WrtPLine2File (int           iKey,
                        DL_Dxf      **dxf,
                        DL_WriterA  **dw);

     //==============================================================================
     /**
     * @brief Get actual MinMax from Dxf PolyLine
     *
     * iStat = GetMinMax ( iKey, *sLocMiMa);
     *
     * More Comment
     *
     * Changed: 14.06.13  Re.
     *
     * @ingroup sst_dxf_lib
     *
     * @param iKey: [in]  For the moment 0
     * @param iKey: [out] MinMax
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author Re.
     *
     * @date 14.06.13
     */
     //------------------------------------------------------------------------------
     // int GetMinMax (int             iKey,
     //               MIMA_3D_Struct *sLocMiMa);
     //==============================================================================

  private:  // Private Funktionen
  DL_PolylineData myTestpoly;    /**< Dxf polyline header */
  std::list <DL_VertexData>  sVertexHeap;      /**< All Vertices in Heap */
  long lActVertex;               /**< vertex number for getvertex */
};
//==============================================================================
/**
* @brief sst Dxf Circle
*
* More Comment
*
* Used Type Definitions
* sstDxf02;Circle;cx;DD;12;4
* sstDxf02;Circle;cy;DD;12;4
* sstDxf02;Circle;cz;DD;12;4
* sstDxf02;Circle;radius;DD;12;4
*
* Changed: 06.07.16  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 06.07.16
*/
// ----------------------------------------------------------------------------
class sstDxf03TypCircleCls  : public sstDxf03TypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03TypCircleCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03TypCircleCls(); // Constructor
    //==============================================================================
    /**
    * @brief // read circle data from dxflib circle <BR>
    * oSstDxfCircle.ReadFromDL(poDLCircle);
    *
    * @param poDLCircle [in] dxflib circle structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_CircleData poDLCircle);
    //==============================================================================
    /**
    * @brief // write circle data to dxflib circle <BR>
    * oSstDxfCircle.WritToDL(poDLCircle);
    *
    * @param poDLCircle [out] dxflib circle structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_CircleData *poDLCircle);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getCx() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setCx(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getCy() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setCy(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getCz() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setCz(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getRadius() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setRadius(double value);
    //==============================================================================
    /**
    * @brief // Get Minimum bounding rectangle  <BR>
    *
    * @return Mbr
    */
    // ----------------------------------------------------------------------------
    sstMath01Mbr2Cls getMbr() const;
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber(); // Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName(); // Function get String of Member Names (csv)
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType(); // Function get String of Member Types (csv)
    //==============================================================================

private:
    double cx;  /**< X Coordinate of center point. */
    double cy;  /**< Y Coordinate of center point. */
    double cz;  /**< Z Coordinate of center point. */
    double radius;  /**< Radius of arc. */
};

//==============================================================================
/**
* @brief function class for sst Dxf Circle
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncCircleCls : public sstDxf03FncBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03FncCircleCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03FncCircleCls(); // // Constructor
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    *
    * @param iKey
    * @param *sErrTxt
    * @param *ssstDxf02_Str
    * @param *osstDxf02TypCircle
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf02_Str, sstDxf03TypCircleCls *osstDxf02TypCircle); // // Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    *
    * @param iKey
    * @param *osstDxf02TypCircle
    * @param *ssstDxf02_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey, sstDxf03TypCircleCls *osstDxf02TypCircle, std::string *ssstDxf02_Str); // // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oDxfFncArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oDxfFncArc.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole arc data from table to csv file  <BR>
    * iStat = oSstFncArc.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================
  private:
};

//==============================================================================
/**
* @brief sst Dxf MText
*
* More Comment
*
* Used Type Definitions
* sstDxf02;MText;ipx;DD;12;4
* sstDxf02;MText;ipy;DD;12;4
* sstDxf02;MText;ipz;DD;12;4
* sstDxf02;MText;dirx;DD;12;4
* sstDxf02;MText;diry;DD;12;4
* sstDxf02;MText;dirz;DD;12;4
* sstDxf02;MText;height;DD;12;4
* sstDxf02;MText;width;DD;12;4
* sstDxf02;MText;attachmentPoint;II;6;0
* sstDxf02;MText;drawingDirection;II;6;0
* sstDxf02;MText;lineSpacingStyle;II;6;0
* sstDxf02;MText;lineSpacingFactor;DD;12;4
* sstDxf02;MText;text;CC;100;0
* sstDxf02;MText;style_ID;UL;10;0
* sstDxf02;MText;angle;DD;12;4
*
* Changed: 06.07.16  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 06.07.16
*/
// ----------------------------------------------------------------------------
class sstDxf03TypMTextCls : public sstDxf03TypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03TypMTextCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03TypMTextCls(); // Constructor
    //==============================================================================
    /**
    * @brief // read arc data from dxflib arc <BR>
    * oSstDxfArc.ReadFromDL(poDLArc);
    *
    * @param poDLMText [in] dxflib MText structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_MTextData poDLMText);
    //==============================================================================
    /**
    * @brief // write arc data to dxflib arc <BR>
    * oSstDxfArc.WritToDL(poDLArc);
    *
    * @param poDLMText [out] dxflib MText structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_MTextData *poDLMText);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getIpx() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setIpx(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getIpy() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setIpy(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getIpz() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setIpz(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getDirx() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setDirx(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getDiry() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setDiry(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getDirz() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setDirz(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getHeight() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setHeight(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getWidth() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setWidth(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    int getAttachmentPoint() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setAttachmentPoint(int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    int getDrawingDirection() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setDrawingDirection(int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    int getLineSpacingStyle() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setLineSpacingStyle(int value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getLineSpacingFactor() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setLineSpacingFactor(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    std::string getText() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setText(std::string value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    unsigned long getStyle_ID() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setStyle_ID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getAngle() const;
    //==============================================================================
    /**
    * @brief // Set Value <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setAngle(double value);
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber(); // Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName(); // Function get String of Member Names (csv)
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType(); // Function get String of Member Types (csv)
    //==============================================================================

private:
    double ipx;  /**< X Coordinate of insertion point */
    double ipy;  /**< Y Coordinate of insertion point */
    double ipz;  /**< Z Coordinate of insertion point */
    double dirx;  /**< X Coordinate of X direction vec */
    double diry;  /**< Y Coordinate of X direction vec */
    double dirz;  /**< Z Coordinate of X direction vec */
    double height;  /**< Text height */
    double width;  /**< Width of the text box. */
    int attachmentPoint;  /**< Attachment point. */
    int drawingDirection;  /**< Drawing direction. */
    int lineSpacingStyle;  /**< Line spacing style. */
    double lineSpacingFactor;  /**< Line spacing factor. */
    char text[101];  /**< Text string. */
    unsigned long style_ID;  /**< Style string. */
    double angle;  /**< Rotation angle. */
};

//==============================================================================
/**
* @brief Funcion class for sst Dxf MText
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncMTextCls : public sstDxf03FncBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03FncMTextCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03FncMTextCls(); // // Constructor
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    * @param iKey
    * @param *sErrTxt
    * @param *ssstDxf02_Str
    * @param *osstDxf02TypMText
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf02_Str, sstDxf03TypMTextCls *osstDxf02TypMText); // // Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    * @param iKey
    * @param *osstDxf02TypMText
    * @param *ssstDxf02_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey, sstDxf03TypMTextCls *osstDxf02TypMText, std::string *ssstDxf02_Str); // // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oDxfFncArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oDxfFncArc.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole arc data from table to csv file  <BR>
    * iStat = oSstFncArc.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================
  private:
};

//==============================================================================
/**
* @brief sst Dxf Text
*
* More Comment
*
* Used Type Definitions
* sstDxf03;Text;ipx;DD;12;4;sst Dxf Lib;sst Text;X Coordinate of insertion point
* sstDxf03;Text;ipy;DD;12;4;sst Dxf Lib;sst Text;Y Coordinate of insertion point
* sstDxf03;Text;ipz;DD;12;4;sst Dxf Lib;sst Text;Z Coordinate of insertion point
* sstDxf03;Text;apx;DD;12;4;sst Dxf Lib;sst Text;X Coordinate of alignment point
* sstDxf03;Text;apy;DD;12;4;sst Dxf Lib;sst Text;Y Coordinate of alignment point
* sstDxf03;Text;apz;DD;12;4;sst Dxf Lib;sst Text;Z Coordinate of alignment point
* sstDxf03;Text;height;DD;12;4;sst Dxf Lib;sst Text;Text height
* sstDxf03;Text;xScaleFactor;DD;12;4;sst Dxf Lib;sst Text;Relative X scale factor.
* sstDxf03;Text;textGenerationFlags;II;6;0;sst Dxf Lib;sst Text;0 = default, 2 = Backwards, 4 =
* sstDxf03;Text;hJustification;II;6;0;sst Dxf Lib;sst Text;Horizontal justification.
* sstDxf03;Text;vJustification;II;6;0;sst Dxf Lib;sst Text;Vertical justification.
* sstDxf03;Text;text;CC;100;0;sst Dxf Lib;sst Text;Text string.
* sstDxf03;Text;style_ID;UL;10;0;sst Dxf Lib;sst Text;Style (font).
* sstDxf03;Text;angle;DD;12;4;sst Dxf Lib;sst Text;Rotation angle of dimension tex
*
* Changed: 06.07.16  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 06.07.16
*/
// ----------------------------------------------------------------------------
class sstDxf03TypTextCls : public sstDxf03TypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03TypTextCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03TypTextCls(); // Constructor
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber();// Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName();// Get Csv-String with all Class member names
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType();// Get Csv-String with all Class member definition types
    //==============================================================================
    /**
    * @brief // read text data from dxflib text <BR>
    * oSstDxfText.ReadFromDL(poDLText);
    *
    * @param poDLText [in] dxflib text structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_TextData poDLText);
    //==============================================================================
    /**
    * @brief // write text data to dxflib text <BR>
    * oSstDxfText.WritToDL(poDLText);
    *
    * @param poDLText [out] dxflib text structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_TextData *poDLText);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getIpx() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setIpx(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getIpy() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setIpy(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getIpz() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setIpz(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getApx() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setApx(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getApy() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setApy(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getApz() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setApz(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getHeight() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setHeight(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getXScaleFactor() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setXScaleFactor(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    int getTextGenerationFlags() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setTextGenerationFlags(int value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    int getHJustification() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setHJustification(int value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    int getVJustification() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setVJustification(int value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    std::string getText() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setText(std::string value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    unsigned long getStyle_ID() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setStyle_ID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return Value
    */
    // ----------------------------------------------------------------------------
    double getAngle() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Value
    */
    // ----------------------------------------------------------------------------
    void setAngle(double value);
    //==============================================================================

private:
    double ipx;  /**< X Coordinate of insertion point */
    double ipy;  /**< Y Coordinate of insertion point */
    double ipz;  /**< Z Coordinate of insertion point */
    double apx;  /**< X Coordinate of alignment point */
    double apy;  /**< Y Coordinate of alignment point */
    double apz;  /**< Z Coordinate of alignment point */
    double height;  /**< Text height */
    double xScaleFactor;  /**< Relative X scale factor. */
    int textGenerationFlags;  /**< 0 = default, 2 = Backwards, 4 = */
    int hJustification;  /**< Horizontal justification. */
    int vJustification;  /**< Vertical justification. */
    char text[101];  /**< Text string. */
    unsigned long style_ID;  /**< Style (font). */
    double angle;  /**< Rotation angle of dimension tex */
};

//==============================================================================
/**
* @brief function class for sst Dxf Text
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncTextCls : public sstDxf03FncBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03FncTextCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03FncTextCls(); // // Constructor
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    * @param iKey
    * @param *sErrTxt
    * @param *ssstDxf02_Str
    * @param *osstDxf02TypText
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf02_Str, sstDxf03TypTextCls *osstDxf02TypText); // // Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    * @param iKey
    * @param *osstDxf02TypText
    * @param *ssstDxf02_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey, sstDxf03TypTextCls *osstDxf02TypText, std::string *ssstDxf02_Str); // // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oDxfFncArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole layer csv file into sst_rec_mem <BR>
    * iStat = oDxfFncArc.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole arc data from table to csv file  <BR>
    * iStat = oSstFncArc.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================
  private:
};
//==============================================================================
/**
* @brief sst Point
*
* More Comment
*
* Used Type Definitions
* sstDxf03;Point;x;DD;12;4
* sstDxf03;Point;y;DD;12;4
* sstDxf03;Point;z;DD;12;4
*
* Changed: 06.07.16  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 06.07.16
*/
// ----------------------------------------------------------------------------
class sstDxf03TypPointCls : public sstDxf03TypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03TypPointCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03TypPointCls(); // Constructor
    //==============================================================================
    /**
    * @brief // read point data from dxflib text <BR>
    * oSstDxfPoint.ReadFromDL(poDLPoint);
    *
    * @param poDLPoint [in] dxflib point structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_PointData poDLPoint);
    //==============================================================================
    /**
    * @brief // write point data to dxflib text <BR>
    * oSstDxfPoint.WritToDL(poDLPoint);
    *
    * @param poDLPoint [out] dxflib point structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_PointData *poDLPoint);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getX() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set value
    */
    // ----------------------------------------------------------------------------
    void setX(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getY() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set value
    */
    // ----------------------------------------------------------------------------
    void setY(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getZ() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set value
    */
    // ----------------------------------------------------------------------------
    void setZ(double value);
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber(); // Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName(); // Function get String of Member Names (csv)
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType(); // Function get String of Member Types (csv)
    //==============================================================================

private:
    double x;  /**< X Coordinate of the point */
    double y;  /**< Y Coordinate of the point */
    double z;  /**< Z Coordinate of the point */
};

//==============================================================================
/**
* @brief Point
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncPointCls : public sstDxf03FncBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03FncPointCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03FncPointCls(); // // Constructor
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    * @param iKey
    * @param *sErrTxt
    * @param *ssstDxf03_Str
    * @param *osstDxf03TypPoint
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf03_Str, sstDxf03TypPointCls *osstDxf03TypPoint); // // Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    * @param iKey
    * @param *osstDxf03TypPoint
    * @param *ssstDxf03_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey, sstDxf03TypPointCls *osstDxf03TypPoint, std::string *ssstDxf03_Str); // // Csv Write Function
    //==============================================================================
    /**
    * @brief // write POINT title row to csv file <BR>
    * iStat = oDxfFncPoint.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole point csv file into sst_rec_mem <BR>
    * iStat = oDxfFncPoint.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole point data from table to csv file  <BR>
    * iStat = oSstFncPoint.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================
  private:
};

//==============================================================================
/**
* @brief sst Line
*
* More Comment
*
* Used Type Definitions
* sstDxf03;Line;x1;DD;12;4
* sstDxf03;Line;y1;DD;12;4
* sstDxf03;Line;z1;DD;12;4
* sstDxf03;Line;x2;DD;12;4
* sstDxf03;Line;y2;DD;12;4
* sstDxf03;Line;z2;DD;12;4
*
* Changed: 06.07.16  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 06.07.16
*/
// ----------------------------------------------------------------------------
class sstDxf03TypLineCls : public sstDxf03TypBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03TypLineCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03TypLineCls(); // Constructor
    //==============================================================================
    /**
    * @brief // read line data from dxflib line <BR>
    * oSstDxfLine.ReadFromDL(poDLLine);
    *
    * @param poDLLine [in] dxflib line structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_LineData poDLLine);
    //==============================================================================
    /**
    * @brief // write line data to dxflib text <BR>
    * oSstDxfLine.WritToDL(poDLLine);
    *
    * @param poDLLine [out] dxflib line structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_LineData *poDLLine);
    //==============================================================================
    /**
    * @brief // Get Minimum Bounding Rectangle  <BR>
    *
    * @return MinMax
    */
    // ----------------------------------------------------------------------------
    sstMath01Mbr2Cls getMinMax() const;
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getX1() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set value
    */
    // ----------------------------------------------------------------------------
    void setX1(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getY1() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set value
    */
    // ----------------------------------------------------------------------------
    void setY1(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getZ1() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set value
    */
    // ----------------------------------------------------------------------------
    void setZ1(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getX2() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set value
    */
    // ----------------------------------------------------------------------------
    void setX2(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getY2() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set value
    */
    // ----------------------------------------------------------------------------
    void setY2(double value);
    //==============================================================================
    /**
    * @brief // Get Value  <BR>
    *
    * @return value
    */
    // ----------------------------------------------------------------------------
    double getZ2() const;
    //==============================================================================
    /**
    * @brief // Set Value  <BR>
    *
    * @param value [in] Set value
    */
    // ----------------------------------------------------------------------------
    void setZ2(double value);
    //==============================================================================
    /**
    * @brief // Get Minimum bounding rectangle  <BR>
    *
    * @return Mbr
    */
    // ----------------------------------------------------------------------------
    sstMath01Mbr2Cls getMbr() const;
    //==============================================================================
    /**
    * @brief // getMemberNumber <BR>
    */
    // -----------------------------------------------------------------------------
    unsigned int getMemberNumber(); // Get Number of Class member
    //==============================================================================
    /**
    * @brief // getStringName <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringName(); // Function get String of Member Names (csv)
    //==============================================================================
    /**
    * @brief // getStringType <BR>
    */
    // -----------------------------------------------------------------------------
    std::string getStringType(); // Function get String of Member Types (csv)
    //==============================================================================

private:
    double x1;  /**< X Start coordinate of the point */
    double y1;  /**< Y Start coordinate of the point */
    double z1;  /**< Z Start coordinate of the point */
    double x2;  /**< X End coordinate of the point */
    double y2;  /**< Y End coordinate of the point */
    double z2;  /**< Z End coordinate of the point */
};

//==============================================================================
/**
* @brief Line
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf03FncLineCls : public sstDxf03FncBaseCls
{
  public:
    //==============================================================================
    /**
    * @brief // sstDxf03FncLineCls <BR>
    */
    // -----------------------------------------------------------------------------
    sstDxf03FncLineCls(); // // Constructor
    //==============================================================================
    /**
    * @brief // Csv_Read <BR>
    * @param iKey
    * @param *sErrTxt
    * @param *ssstDxf03_Str
    * @param *osstDxf03TypLine
    */
    // -----------------------------------------------------------------------------
    int Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxf03_Str, sstDxf03TypLineCls *osstDxf03TypLine); // // Csv Read Function
    //==============================================================================
    /**
    * @brief // Csv_Write <BR>
    * @param iKey
    * @param *osstDxf03TypLine
    * @param *ssstDxf03_Str
    */
    // -----------------------------------------------------------------------------
    int Csv_Write(int iKey, sstDxf03TypLineCls *osstDxf03TypLine, std::string *ssstDxf03_Str); // // Csv Write Function
    //==============================================================================
    /**
    * @brief // write LINE title row to csv file <BR>
    * iStat = oDxfFncLine.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================
    /**
    * @brief // Read whole line csv file into sst_rec_mem <BR>
    * iStat = oDxfFncLine.ReadCsvFile ( iKey, oFilNam);
    *
    * @param iKey    [in] For the moment 0
    * @param oFilNam [in] File name to import to rec mem
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    * @retval   = -2: Open File Error
    * @retval   = -3: General read error
    * @retval   = -4: Record format read Error
    * @retval   <  0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int ReadCsvFile(int iKey, std::string oFilNam);
    //==============================================================================
    /**
    * @brief // write whole line data from table to csv file  <BR>
    * iStat = oSstFncLine.WriteCsvFile ( iKey, oDxfFilNam);
    *
    * @param iKey       [in] For the moment 0
    * @param oDxfFilNam [in] File name to export to csv file
    *
    * @return Errorstate
    *
    * @retval   =  0: OK
    * @retval   = -1: Wrong Key
    */
    // ----------------------------------------------------------------------------
    int WriteCsvFile(int iKey, std::string oDxfFilNam);
    //==============================================================================
  private:
};
//==============================================================================
/**
* @brief sst dxf database class
*
* Stores all dxf types <BR>
*
* Changed: 06.04.16  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 06.04.16
*/
// ----------------------------------------------------------------------------
class sstDxf03DatabaseCls
{
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // dxf database constructor <BR>
  *
  * @param oTmpPrt [in] protocol output file
  */
  // ----------------------------------------------------------------------------
     sstDxf03DatabaseCls(sstMisc01PrtFilCls *oTmpPrt);  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Read all Csv Files into dxf database <BR>
     * iStat = oSstDxfDB.ReadAllCsvFiles(iKey);
     *
     * @param iKey       [in] For the moment 0
     * @param oDxfFilNam [in] Dxf File Name for new dxf file
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
     * @brief // get layer table adress from dxf database <BR>
     * oLayTab = oDxfDB.getSstFncLay();
     *
     * @return Layer table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncLayCls* getSstFncLay();
     //==============================================================================
     /**
     * @brief // get block table adress from dxf database <BR>
     * oBlkTab = oDxfDB.getSstFncBlk();
     *
     * @return Block table adress
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncBlkCls* getSstFncBlk();
     //==============================================================================
     /**
     * @brief // get LType table adress from dxf database <BR>
     * oBlkTab = oDxfDB.getSstFncLType();
     *
     * @return LineType table adress
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncLTypeCls* getSstFncLType();
     //==============================================================================
     /**
     * @brief // get arc table adress from dxf database <BR>
     * oArcTab = oDxfDB.getSstFncArc();
     *
     * @return Layer table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncArcCls* getSstFncArc();
     //==============================================================================
     /**
     * @brief // get circle table adress from dxf database <BR>
     * oCircleTab = oDxfDB.getSstFncCircle();
     *
     * @return Circle table adress
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncCircleCls* getSstFncCircle();
     //==============================================================================
     /**
     * @brief // get mtext table adress from dxf database <BR>
     * oMTextTab = oDxfDB.getSstFncMText();
     *
     * @return MText table adress
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncMTextCls* getSstFncMText();
     //==============================================================================
     /**
     * @brief // get text table adress from dxf database <BR>
     * oTextTab = oDxfDB.getSstFncText();
     *
     * @return Text table adress
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncTextCls* getSstFncText();
     //==============================================================================
     /**
     * @brief // get point table adress from dxf database <BR>
     * oPointTab = oDxfDB.getSstFncPoint();
     *
     * @return point table adress
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncPointCls* getSstFncPoint();
     //==============================================================================
     /**
     * @brief // get line table adress from dxf database <BR>
     * oLineTab = oDxfDB.getSstFncLine();
     *
     * @return Line table adress
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncLineCls* getSstFncLine();
     //==============================================================================
     /**
     * @brief // get insert table from dxf database <BR>
     * oInsertTab = oDxfDB.getSstFncInsert();
     *
     * @return insert table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncInsertCls* getSstFncInsert();
     //==============================================================================
     /**
     * @brief // get polyline table from dxf database <BR>
     * oInsertTab = oDxfDB.getSstFncPolyline();
     *
     * @return polyline table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncPolylineCls* getSstFncPolyline();
     //==============================================================================
     /**
     * @brief // get trace table from dxf database <BR>
     * oTraceTab = oDxfDB.getSstFncTrace();
     *
     * @return trace table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncTraceCls* getSstFncTrace();
     //==============================================================================
     /**
     * @brief // get vertex table from dxf database <BR>
     * oVertexTab = oDxfDB.getSstFncVertex();
     *
     * @return vertex table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncVertexCls* getSstFncVertex();
     //==============================================================================
     /**
     * @brief // get hatch table from dxf database <BR>
     * oHatchTab = oDxfDB.getSstFncHatch();
     *
     * @return hatch table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncHatchCls* getSstFncHatch();
     //==============================================================================
     /**
     * @brief // get hatch edge table from dxf database <BR>
     * oHatchEdgeTab = oDxfDB.getSstFncHatchEdge();
     *
     * @return hatch edge table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncHatchEdgeCls* getSstFncHatchEdge();
     //==============================================================================
     /**
     * @brief // get hatch loop table from dxf database <BR>
     * oHatchLoopTab = oDxfDB.getSstFncHatchLoop();
     *
     * @return hatch Loop table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncHatchLoopCls* getSstFncHatchLoop();
     //==============================================================================
     /**
     * @brief // get main table from dxf database <BR>
     * oMainTab = oDxfDB.getSstFncMain();
     *
     * @return Layer table
     */
     // ----------------------------------------------------------------------------
     sstDxf03FncMainCls* getSstFncMain();
     //==============================================================================
     /**
     * @brief // return Start of section entities in main table <BR>
     *
     * @return Record number
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP getMainTabSectEntStart() const;
     //==============================================================================
     /**
     * @brief // Set Start of section entities in main table <BR>
     *
     * @param value [in] record number
     */
     // ----------------------------------------------------------------------------
     void setMainTabSectEntStart(const dREC04RECNUMTYP &value);
     //==============================================================================
     /**
     * @brief // return actual entity type <BR>
     *
     * @return actual entity type
     */
     // ----------------------------------------------------------------------------
     RS2::EntityType getActEntType() const;
     //==============================================================================
     /**
     * @brief // Set actual entity type <BR>
     *
     * @param value [in] actual entity type
     */
     // ----------------------------------------------------------------------------
     void setActEntType(const RS2::EntityType &value);
     //==============================================================================
     /**
     * @brief // Write new Circle into dxf database <BR>
     * iStat = oDxfDbInt.WriteNewCircle(iKey,oDLCircle,oDLAttributes, &oEntRecNo, &oMainRecNo);
     *
     * @param iKey          [in] For the moment 0
     * @param oDLCircle     [in] For the moment 0
     * @param oDLAttributes [in] For the moment 0
     * @param oEntRecNo     [out] For the moment 0
     * @param oMainRecNo    [out] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteNewCircle(int iKey,
                        const DL_CircleData  oDLCircle,
                        const DL_Attributes  oDLAttributes,
                        dREC04RECNUMTYP     *oEntRecNo,
                        dREC04RECNUMTYP     *oMainRecNo);
     //==============================================================================
     /**
     * @brief // Rewrite existing or write new Circle entity into dxf database <BR>
     * iStat = oDxfDbInt.WriteCircle (iKey,oDLCircle,oDLAttributes, &oEntRecNo, &oMainRecNo);
     *
     * @param iKey          [in] For the moment 0
     * @param oDLCircle     [in] Circle Entity
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
     int WriteCircle (int                  iKey,
                      const DL_CircleData  oDLCircle,
                      const DL_Attributes  oDLAttributes,
                      dREC04RECNUMTYP     *oEntRecNo,
                      dREC04RECNUMTYP     *oMainRecNo);
     //==============================================================================
     /**
     * @brief // Rewrite existing or write new Point entity into dxf database <BR>
     * iStat = oDxfDbInt.WritePoint (iKey,oDLPoint,oDLAttributes, &oEntRecNo, &oMainRecNo);
     *
     * @param iKey          [in] For the moment 0
     * @param oDLPoint      [in] Point Entity
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
     int WritePoint (int                  iKey,
                     const DL_PointData   oDLPoint,
                     const DL_Attributes  oDLAttributes,
                     dREC04RECNUMTYP     *oEntRecNo,
                     dREC04RECNUMTYP     *oMainRecNo);
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
     * @brief // Rewrite existing or write new MText entity into dxf database <BR>
     * iStat = oDxfDbInt.WriteMText (iKey,oDlMText,oDLAttributes, &oEntRecNo, &oMainRecNo);
     *
     * @param iKey          [in] For the moment 0
     * @param oDlMText       [in] MText Entity
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
     int WriteMText (int iKey,
                    const DL_MTextData    oDlMText,
                    const DL_Attributes  oDLAttributes,
                    dREC04RECNUMTYP     *oEntRecNo,
                    dREC04RECNUMTYP     *oMainRecNo);
     //==============================================================================
     /**
     * @brief // Rewrite existing or write new Text entity into dxf database <BR>
     * iStat = oDxfDbInt.WriteText (iKey,oDlText,oDLAttributes, &oEntRecNo, &oMainRecNo);
     *
     * @param iKey          [in] For the moment 0
     * @param oDlText       [in] Text Entity
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
     int WriteText (int iKey,
                    const DL_TextData    oDlText,
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
     * @brief // Shortstory <BR>
     * iStat = oTestBase.Func_1(iKey);
     *
     * @param iKey [in] For the moment 0
     * @param oDxfFilNam [in] For the moment 0
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
     * @brief // Shortstory <BR>
     * iStat = oTestBase.Func_1(iKey);
     *
     * @param iKey [in] For the moment 0
     * @param oDxfFilNam [in] For the moment 0
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
     * @brief // Shortstory <BR>
     * iStat = oTestBase.Func_1(iKey);
     *
     * @return Protocol adress
     */
     // ----------------------------------------------------------------------------
     sstMisc01PrtFilCls* GetPrtAdr();
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * iStat = oTestBase.Func_1(iKey);
     *
     * @param iKey [in] For the moment 0
     * @param oDxfFilNam [in] For the moment 0
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
     * @brief // Read hatch edge from table <BR>
     * iStat = oDxfDb.ReadHatchEdge( iKey, dRecNo, &oDLHatchEdge);
     *
     * @param iKey [in] For the moment 0
     * @param dRecNo [int] Record number in table
     * @param oDLHatchEdge [out] Return Hatch
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
     * @brief // Read Line from table with attributes <BR>
     * iStat = oDxfDb.ReadLine( iKey, dRecNo, &oDLLine, &oDLAttributes);
     *
     * @param iKey [in] For the moment 0
     * @param dRecNo [int] Record number in table
     * @param oDLLine [out] Return Line
     * @param oDLAttributes [out] Return Circle attributes
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadLine ( int iKey, dREC04RECNUMTYP dRecNo, DL_LineData *oDLLine, DL_Attributes *oDLAttributes);
     //==============================================================================
     /**
     * @brief // Read Point from table with attributes <BR>
     * iStat = oDxfDb.ReadPoint( iKey, dRecNo, &oDLPoint, &oDLAttributes);
     *
     * @param iKey          [in] For the moment 0
     * @param dRecNo        [int] Record number in table
     * @param oDLPoint      [out] Return Point
     * @param oDLAttributes [out] Return Circle attributes
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadPoint ( int iKey, dREC04RECNUMTYP dRecNo, DL_PointData *oDLPoint, DL_Attributes *oDLAttributes);
     //==============================================================================
     /**
     * @brief // Read MText from table with attributes <BR>
     * iStat = oDxfDb.ReadMText( iKey, dRecNo, &oDLMText, &oDLAttributes);
     *
     * @param iKey          [in] For the moment 0
     * @param dRecNo        [int] Record number in table
     * @param oDLMText      [out] Return MText
     * @param oDLAttributes [out] Return Circle attributes
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadMText ( int iKey, dREC04RECNUMTYP dRecNo, DL_MTextData *oDLMText, DL_Attributes *oDLAttributes);
     //==============================================================================
     /**
     * @brief // Read Text from table with attributes <BR>
     * iStat = oDxfDb.ReadText( iKey, dRecNo, &oDlText, &oDLAttributes);
     *
     * @param iKey          [in] For the moment 0
     * @param dRecNo        [int] Record number in table
     * @param oDlText      [out] Return Text
     * @param oDLAttributes [out] Return Circle attributes
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int ReadText ( int iKey, dREC04RECNUMTYP dRecNo, DL_TextData *oDlText, DL_Attributes *oDLAttributes);
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
     * @brief // Read information in main table <BR>
     * iStat = oDxfDb.ReadMainTable( iKey, dRecNo);
     *
     * @param iKey        [in] For the moment 0
     * @param dMainRecNo  [int] Record number in main table
     * @param eEntityType [out] return entity type
     * @param dEntRecNo   [out] return entity record number
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
     * @brief // Update all minimum bounding rectangles <BR>
     * iStat = oDxfDb.updateAllMbr( iKey);
     *
     * @param iKey        [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int updateAllMbr(int iKey);
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
     * @brief // Update DL Attributes with Layer/LType Identifier <BR>
     * iStat = oDxfDb.UpdateAttribWithId( iKey, dLayId, dLTypeId, &oDLAttributes);
     *
     * @param iKey          [in]  For the moment 0
     * @param dLayID        [in]  Layer Identifier
     * @param dLTypeID      [in]  Linetype Identifier
     * @param oDLAttributes [out] update DL Attributes
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int UpdateAttribWithId (int iKey,
                          dREC04RECNUMTYP dLayID,
                          dREC04RECNUMTYP dLTypeID,
                          DL_Attributes *oDLAttributes);
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
     * @brief // return number of blocks in sstDxfDb <BR>
     * dNumBlocks = oDxfDb.countBlocks();
     *
     * @return Number of records in block table
     */
     // ----------------------------------------------------------------------------
     dREC04RECNUMTYP countEntities(int iKey, dREC04RECNUMTYP dBlkNo);
     //==============================================================================
     //==============================================================================
     /**
     * @brief // return type of entitiy in actual block in sstDxfDb <BR>
     * dNumEntities = oDxfDb.countEntities (iKey, dBlkNo);
     *
     * @param iKey       [in] For the moment 0
     * @param dBlkNo     [in] Block number (=0: model space)
     * @param dMainNo    [in] Number in Main table
     * @param eEntType   [out] enum entity type
     * @param dEntNo     [out] Number in Entity table
     *
     * @return Type of entity
     */
     // ----------------------------------------------------------------------------
     int ReadEntityType(int iKey,
                        dREC04RECNUMTYP  dBlkNo,
                        dREC04RECNUMTYP  dMainNo,
                        RS2::EntityType *eEntType,
                        dREC04RECNUMTYP *dEntNo);
     //==============================================================================

private:  // Private functions

  sstDxf03FncMainCls oSstFncMain;      /**< Main table object */
  sstDxf03FncLayCls oSstFncLay;        /**< layer table object */
  sstDxf03FncBlkCls oSstFncBlk;        /**< Block table object */
  sstDxf03FncLTypeCls oSstFncLType;        /**< LineType table object */
  sstDxf03FncArcCls oSstFncArc;        /**< Arc table object */
  sstDxf03FncTraceCls oSstFncTrace;        /**< Trace table object */
  sstDxf03FncCircleCls oSstFncCircle;        /**< Circle table object */
  sstDxf03FncMTextCls oSstFncMText;        /**< MText table object */
  sstDxf03FncTextCls oSstFncText;        /**< Text table object */
  sstDxf03FncPointCls oSstFncPoint;        /**< Point table object */
  sstDxf03FncLineCls oSstFncLine;        /**< Line table object */
  sstDxf03FncInsertCls oSstFncInsert;  /**< Insert table object */
  sstDxf03FncPolylineCls oSstFncPolyline;  /**< polyline table object */
  sstDxf03FncVertexCls oSstFncVertex;  /**< vertex table object */
  sstDxf03FncHatchCls oSstFncHatch;    /**< hatch table object */
  sstDxf03FncHatchEdgeCls oSstFncHatchEdge;  /**< hatch edge table object */
  sstDxf03FncHatchLoopCls oSstFncHatchLoop;  /**< hatch loop table object */
  sstMisc01PrtFilCls *oPrt;                  /**< Protocol object */
  // dREC04RECNUMTYP dActRecNo;              // Actual Record Number from what?? Unused??
  dREC04RECNUMTYP dMainTabSectEntStart;          // Start of entity section in main table
  RS2::EntityType eActEntType;            // Actual Entity Type
  std::string sActLayBlkNam;              // Actual Layer/Block Name
  RS2::EntityType eGrpEntType;            // Group Entity Type
  dREC04RECNUMTYP dGrpMainID;             // Group Main ID
  dREC04RECNUMTYP dGrpSubID;              // Sub Group ID like HatchLoop
  dREC04RECNUMTYP dGrpRecNum;             // Number of entities
};
/**
* @brief Dxf Import Data Class <BR>
*
* Changed: 09.07.15  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf03ReadCls : public DL_CreationAdapter {
public:
  //==============================================================================
  /**
  * @brief // dxf read object with database <BR>
  *
  * @param oDxfDb  [in out] sst dxf database
  * @param oTmpPrt [in] protocol output file
  */
  // ----------------------------------------------------------------------------
    sstDxf03ReadCls(sstDxf03DatabaseCls *oDxfDb, sstMisc01PrtFilCls *oTmpPrt);
    ~sstDxf03ReadCls();
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addLayer(const DL_LayerData& data);
    //==============================================================================
    /**
    * @brief // Process imported Block data <BR>
    * oSstDxfReadDL.addBlock(data)
    *
    * @param data [in] BlockData
    */
    // ----------------------------------------------------------------------------
    virtual void addBlock(const DL_BlockData& data);
    //==============================================================================
    /**
    * @brief // process end block situation <BR>
    * oSstDxfReadDL.endBlock()
    */
    // ----------------------------------------------------------------------------
    virtual void endBlock();
    //==============================================================================
    /**
    * @brief // Process imported Point data <BR>
    * oSstDxfReadDL.addPoint(data)
    *
    * @param data [in] Point data
    */
    // ----------------------------------------------------------------------------
    virtual void addPoint(const DL_PointData& data);
    //==============================================================================
    /**
    * @brief // Process imported insert data <BR>
    * oSstDxfReadDL.addInsert(data)
    *
    * @param data [in] insert data
    */
    // ----------------------------------------------------------------------------
    virtual void addInsert(const DL_InsertData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addLine(const DL_LineData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addArc(const DL_ArcData& data);
    //==============================================================================
    /**
    * @brief // Import circle data <BR>
    * oSstDxfReadDL.addCircle(data)
    *
    * @param data [in] Circle Data
    */
    // ----------------------------------------------------------------------------
    virtual void addCircle(const DL_CircleData& data);
    //==============================================================================
    /**
    * @brief // Import MText data <BR>
    * oSstDxfReadDL.addMText(data)
    *
    * @param data [in] MText Data
    */
    // ----------------------------------------------------------------------------
    virtual void addMText(const DL_MTextData& data);
    //==============================================================================
    /**
    * @brief // Import Text data <BR>
    * oSstDxfReadDL.addText(data)
    *
    * @param data [in] Text Data
    */
    // ----------------------------------------------------------------------------
    virtual void addText(const DL_TextData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addPolyline(const DL_PolylineData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addVertex(const DL_VertexData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void add3dFace(const DL_3dFaceData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addHatch(const DL_HatchData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addHatchEdge(const DL_HatchEdgeData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addHatchLoop(const DL_HatchLoopData& data);
    //==============================================================================
    /**
    * @brief // Process imported solid data <BR>
    * oSstDxfReadDL.addSolid(data)
    *
    * @param data [in] SolidData
    */
    // ----------------------------------------------------------------------------
    virtual void addSolid(const DL_SolidData& data);
    //==============================================================================
    /**
    * @brief // Print Attributes <BR>
    * oSstDxfReadDL.printAttributes()
    */
    // ----------------------------------------------------------------------------
    // void printAttributes();
    //==============================================================================
    /**
    * @brief // Set Dxf File Name into object <BR>
    * oSstDxfReadDL.SetDxfFilNam(cDxfFilNam);
    *
    * @param cDxfFilNam [in] Set Dxf File Name
    *
    */
    // ----------------------------------------------------------------------------
    void SetDxfFilNam(char* cDxfFilNam);
    //==============================================================================
private:
    sstDxf03DatabaseCls   *poDxfDb; /**< sst dxf database with recmem tech */

    std::string oDxfFilNam;        /**< dxf file name without extension */
    std::string oActBlockNam;      /**< actual block name */
    sstMisc01PrtFilCls *poPrt;     /**< adress of protocol file */
};
//=================================================================================
/**
* @brief sstdxf_WrtDss2PolyLine
*
* iStat = sstdxf_WrtDss2PolyLine ( iKey, *sPntDss, **dxf, **dw);
*
* More Comment
*
* Changed: 16.02.10  Re.
*
* @ingroup sstDxf03LibInt
*
* @param iKey    [in] For the moment 0
* @param sPntDss [in out]
* @param dxf     [in out]
* @param dw      [in out]
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 16.02.10
*/
//------------------------------------------------------------------------------
int sstdxf_WrtDss2PolyLine (int           iKey,
                            sstRec04Cls  *sPntDss,
                            DL_Dxf      **dxf,
                            DL_WriterA  **dw);
//==============================================================================
/**
* @brief dxf write class
*
* Read all csv files, create sst dxf database and export to dxf file <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf03LibInt
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf03WriteCls
{
  public:   // Public functions
  //==============================================================================
  /**
  * @brief // Constructor <BR>
  *
  * @param oDxfDb [in] existing sst Dxf Database
  * @param oTmpPrt [in] protocol file object
  */
  // ----------------------------------------------------------------------------
     sstDxf03WriteCls(sstDxf03DatabaseCls *oDxfDb, sstMisc01PrtFilCls *oTmpPrt);  // Constructor
    ~sstDxf03WriteCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Open new dxf file <BR>
     * iStat = oSstDxfWrite.OpenNewDxfFile ( iKey, oDxfFilNam);
     *
     * @param iKey       [in] For the moment 0
     * @param oDxfFilNam [in] Dxf file name
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int OpenNewDxfFile (int iKey, std::string oDxfFilNam);
     //==============================================================================
     /**
     * @brief // Write dxf section header <BR>
     * iStat = oSstDxfWrite.WrtSecHeader(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecHeader (int         iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Section layers <BR>
     * iStat = oSstDxfWrite.WrtSecLayers(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecLayers (int         iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Section Blocks <BR>
     * iStat = oSstDxfWrite.WrtSecBlocks(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecBlocks (int         iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Section Types <BR>
     * iStat = oSstDxfWrite.WrtSecTypes(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecTypes (int          iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Sectin Styles <BR>
     * iStat = oSstDxfWrite.WrtSecStyles(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecStyles (int          iKey);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * iStat = oSstDxfWrite.Func_1(iKey)
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecEntities (int          iKey);
     //==============================================================================
     /**
     * @brief // Write Dxf Section objects <BR>
     * iStat = oSstDxfWrite.WrtSecObjects(iKey)
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtSecObjects (int          iKey);
     //==============================================================================
     /**
     * @brief // Write Polyline into section entities <BR>
     * iStat = oSstDxfWrite.WrtDss2Polyline(iKey,sPntDss);
     *
     * @param iKey    [in] For the moment 0
     * @param sPntDss [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WrtDss2PolyLine (int           iKey,
                          sstRec04Cls  *sPntDss);
     //==============================================================================
     /**
     * @brief Set Dxf File name
     *
     * @param oDxfFilNam [in] Dxf File Name
     */
     // ----------------------------------------------------------------------------
     void SetDxfFilNam(std::string oDxfFilNam);
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
     int ReadAllCsvFiles(int iKey);
     //==============================================================================
     /**
     * @brief // Close open object like polyline, if nessasary  <BR>
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int WriteOpenEntities(int iKey);
// ----------------------------------------------------------------------------
private:  // Private functions
  DL_Dxf* dxf;     /**< dxflib dxf */
  DL_WriterA* dw;  /**< dxflib dw */
  sstDxf03DatabaseCls   *poDxfDb; /**< sst dxf database with all tables */
  std::string oDxfFilNam;      /**< dxf file name without extension */
  sstMisc01PrtFilCls *poPrt;     /**< adress of protocol file */

};
//==============================================================================



#endif

// --------------------------------------------------------------- File End ----

