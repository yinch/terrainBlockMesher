/*---------------------------------------------------------------------------*\
                               |
  _____        _______ ____    | IWESOL: IWES Open Library
 |_ _\ \      / / ____/ ___|   |
  | | \ \ /\ / /|  _| \___ \   | Copyright: Fraunhofer Institute for Wind
  | |  \ V  V / | |___ ___) |  | Energy and Energy System Technology IWES
 |___|  \_/\_/  |_____|____/   |
                               | http://www.iwes.fraunhofer.de
                               |
-------------------------------------------------------------------------------
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright  held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of IWESOL and it is based on OpenFOAM.

    IWESOL and OpenFOAM are free software: you can redistribute them and/or modify
    them under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    IWESOL and OpenFOAM are distributed in the hope that they will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::oldev::STLProjecting

Description

SourceFiles
    STLProjecting.C

\*---------------------------------------------------------------------------*/

#ifndef STLProjecting_H
#define STLProjecting_H

#include "fvMesh.H"
#include "searchableSurface.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace oldev
{

/*---------------------------------------------------------------------------*\
                         Class STLProjecting Declaration
\*---------------------------------------------------------------------------*/

class STLProjecting
{
    // Private data

		/// the stl
		searchableSurface const * stl_;


protected:

	    // Member Functions

		/// attach a point to stl. returns success.
		virtual bool attachPoint
		(
				point & p,
				const point & p_projectTo
		) const;

		/// project a point to stl, using a direction vector. returns success.
		virtual bool projectPoint
		(
				point & p,
				const Foam::vector & dir_proj,
				scalar maxDist = 100000
		) const;


public:

    // Constructors

        /// Construct null
        STLProjecting();

    	/// Constructor
    	STLProjecting(searchableSurface const * stl);


    /// Destructor
    virtual ~STLProjecting();


    // Member Functions

        // Access

		/// Returns the underlying stl
		searchableSurface const * getSTL() const { return stl_; }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace oldev

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
