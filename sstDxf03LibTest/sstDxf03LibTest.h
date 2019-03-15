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
* @brief // Testframe for reading functions <BR>
* iStat = Test_ReadInterface ( iKey);
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
int Test_ReadInterface (int iKey, sstDxf03DbCls *oDxfDB);
//==============================================================================


#endif // SSTDXF03LIBTEST_HEADER

