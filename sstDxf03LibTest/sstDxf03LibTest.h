/**********************************************************************
 *
 * sstDxf02LibTest - sst dxf library
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
// sstDxf03LibTest.h   16.05.18  Re.    13.07.16  Re.
//

#ifndef SSTDXF03LIBTEST_HEADER
#define SSTDXF03LIBTEST_HEADER

//==============================================================================
/**
* @brief Original testwriting example from dxflib
*
* iStat = testWriting ( oDxfFilNam);
*
* More Comment
*
* Changed: 09.05.18  Re.
*
* @ingroup sstDxf03Lib
*
* @param oDxfFilNam [in] Name of new dxf file
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 09.05.18
*/
//------------------------------------------------------------------------------
int testWriting (const std::string oDxfFilNam);
//==============================================================================
/**
* @brief Original testwriting example from dxflib extended with block writing
*
* iStat = testWriting2 ( oDxfFilNam);
*
* Additional write two blocks and use with inserts.
*
* Changed: 09.05.18  Re.
*
* @ingroup sstDxf03Lib
*
* @param oDxfFilNam [in] Name of new dxf file
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 09.05.18
*/
//------------------------------------------------------------------------------
int testWriting2 (const std::string oDxfFilNam);
//==============================================================================
/**
* @brief // Testframe for writing functions <BR>
* iStat = Test_WriteInterface ( iKey);
*
* More Comment
*
* Changed: 13.03.19  Re.
*
* @ingroup examples
*
* @param iKey [in] For the moment 0
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 13.03.19
*/
//------------------------------------------------------------------------------
int Test_WriteInterface (int iKey, sstDxf03DbCls *oDxfDB);
//==============================================================================
/**
* @brief // Test Write Hatch into sstDxf Database <BR>
* iStat = Test_WriteHatch ( iKey, poDxfDb, dXX, dYY);
*
* 0: Triangel Area
* 1: 4-Corner-Box Area
* 2: Circle Area
* 3: Arc Area
*
* Changed: 30.08.19  Re.
*
* @ingroup sstDxf03Lib
*
* @param iKey    [in]     0,1,2,3
* @param poDxfDb [in out] open sstDxf Database
* @param dXX     [in]     Center X
* @param dYY     [in]     Center Y
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 15.03.19
*/
//------------------------------------------------------------------------------
int Test_WriteHatch (int iKey, sstDxf03DbCls *poDxfDb, const double dXX, const double dYY);
//==============================================================================
/**
* @brief // Test Write Polyline into sstDxf Database <BR>
* iStat = Test_WritePolyline ( iKey, poDxfDb, dXX, dYY);
*
* More Comment
*
* Changed: 15.03.19  Re.
*
* @ingroup examples
*
* @param iKey    [in]     For the moment 0
* @param poDxfDb [in out] open sstDxf Database
* @param dXX     [in]     Center X
* @param dYY     [in]     Center Y
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 15.03.19
*/
//------------------------------------------------------------------------------
int Test_WritePolyline (int iKey, sstDxf03DbCls *poDxfDb, const double dXX, const double dYY);
//==============================================================================
/**
* @brief // Test Write Circle with Radius = 0.5 into sstDxf Database <BR>
* iStat = Test_WriteCircle ( iKey, poDxfDb, dXX, dYY);
*
* More Comment
*
* Changed: 15.03.19  Re.
*
* @ingroup examples
*
* @param iKey    [in]     For the moment 0
* @param poDxfDb [in out] open sstDxf Database
* @param dXX     [in]     Center X
* @param dYY     [in]     Center Y
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 15.03.19
*/
//------------------------------------------------------------------------------
int Test_WriteCircle (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY);
//==============================================================================
/**
* @brief // Test Write Line into sstDxf Database <BR>
* iStat = Test_WriteLine ( iKey, poDxfDb, dXX, dYY);
*
* More Comment
*
* Changed: 15.03.19  Re.
*
* @ingroup examples
*
* @param iKey    [in]     For the moment 0
* @param poDxfDb [in out] open sstDxf Database
* @param dXX     [in]     Center X
* @param dYY     [in]     Center Y
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 15.03.19
*/
//------------------------------------------------------------------------------
int Test_WriteLine (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY);
//==============================================================================
/**
* @brief // Test Write Arc into sstDxf Database <BR>
* iStat = Test_WriteArc ( iKey, poDxfDb, dXX, dYY);
*
* Dxf-Angles are always Grad (0,90,180,270,360)
* Dxf-Angle = 0 is always in East.
* Dxf-Angles are running always counter-Clockwise.
*
* Key=0: Write 8 90-Arcs with incresing Radius and Startangle beginning at Angle = 0:
* Key=1: Write 8 90-Arcs with incresing Radius and Startangle beginning at Angle = 45:
* Key=2: Write 8 270-Arcs with incresing Radius and Startangle beginning at Angle = 0:
* Key=3: Write 8 270-Arcs with incresing Radius and Startangle beginning at Angle = 45:
*
* Changed: 15.03.19  Re.
*
* @ingroup examples
*
* @param iKey    [in]     0-3
* @param poDxfDb [in out] open sstDxf Database
* @param dXX     [in]     Center X
* @param dYY     [in]     Center Y
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 15.03.19
*/
//------------------------------------------------------------------------------
int Test_WriteArc (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY);
//==============================================================================
/**
* @brief // Test Write Text into sstDxf Database <BR>
* iStat = Test_WriteText ( iKey, poDxfDb, dXX, dYY);
*
* More Comment
*
* Changed: 15.03.19  Re.
*
* @ingroup examples
*
* @param iKey    [in]     For the moment 0
* @param poDxfDb [in out] open sstDxf Database
* @param dXX     [in]     Center X
* @param dYY     [in]     Center Y
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 15.03.19
*/
//------------------------------------------------------------------------------
int Test_WriteText (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY);
//==============================================================================
/**
* @brief // Test Write MText into sstDxf Database <BR>
* iStat = Test_WriteMText ( iKey, poDxfDb, dXX, dYY);
*
* More Comment
*
* Changed: 27.03.19  Re.
*
* @ingroup examples
*
* @param iKey    [in]     For the moment 0
* @param poDxfDb [in out] open sstDxf Database
* @param dXX     [in]     Center X
* @param dYY     [in]     Center Y
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 27.03.19
*/
//------------------------------------------------------------------------------
int Test_WriteMText (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY);
//==============================================================================
/**
* @brief // Test Write Point entity into sstDxf Database <BR>
* iStat = Test_WritePoint ( iKey, poDxfDb, dXX, dYY);
*
* More Comment
*
* Changed: 27.03.19  Re.
*
* @ingroup examples
*
* @param iKey    [in]     For the moment 0
* @param poDxfDb [in out] open sstDxf Database
* @param dXX     [in]     Center X
* @param dYY     [in]     Center Y
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 27.03.19
*/
//------------------------------------------------------------------------------
int Test_WritePoint (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY);
//==============================================================================
/**
* @brief // Test Write Insert entity into sstDxf Database <BR>
* iStat = Test_WriteInsert ( iKey, poDxfDb, dXX, dYY);
*
* Key = 0: Write 2-Line-Cross as Block Sym1 and insert at given position.
* Key = 1: Write Circle as Block Sym2 and insert at given position.
* Key = 2: Write Hatch as Block Sym3 and insert at given position.
*
* Changed: 27.03.19  Re.
*
* @ingroup examples
*
* @param iKey    [in]     0,1,2
* @param poDxfDb [in out] open sstDxf Database
* @param dXX     [in]     Center X
* @param dYY     [in]     Center Y
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 27.03.19
*/
//------------------------------------------------------------------------------
int Test_WriteInsert (int iKey, sstDxf03DbCls *oDxfDB, const double dXX, const double dYY);
//==============================================================================
int Test_WriteBlock (int iKey, sstDxf03DbCls *oDxfDB);
//==============================================================================


#endif // SSTDXF03LIBTEST_HEADER

