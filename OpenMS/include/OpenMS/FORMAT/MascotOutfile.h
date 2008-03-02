// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// --------------------------------------------------------------------------
//                   OpenMS Mass Spectrometry Framework
// --------------------------------------------------------------------------
//  Copyright (C) 2003-2008 -- Oliver Kohlbacher, Knut Reinert
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------
// $Maintainer: Nico Pfeifer $
// --------------------------------------------------------------------------

#ifndef OPENMS_FORMAT_MASCOTOUTFILE_H
#define OPENMS_FORMAT_MASCOTOUTFILE_H

#include <OpenMS/CONCEPT/Types.h>
#include <OpenMS/METADATA/PeptideIdentification.h>
#include <OpenMS/METADATA/ProteinIdentification.h>
#include <OpenMS/CONCEPT/Exception.h>

#include <vector>

namespace OpenMS
{
  /**
    @brief Representation of a Mascot output file
    
    This class serves to read in a Mascot outfile. The information can be 
    retrieved via the load function.
  	
  	@todo Handle Modifications (Andreas)
  	
  	@ingroup FileIO
  */
  class MascotOutfile
  {
    public:
      
      /// Constructor
      MascotOutfile();

		  /**
		    @brief loads data from a Mascot outfile
		    
		    @param filename the file to be loaded
		    @param protein_identification the protein identification
		    @param peptide_identifications the peptide identifications
				@param p the significance level (for the protein hit scores)

		    This class serves to read in a Mascot outfile. The information can be 
		    retrieved via the load function. This class is only contained to be compatible with previous versions.
		    You should use the MascotXMLFile instead. 
		  */
			void load(String filename, ProteinIdentification& protein_identification, std::vector<PeptideIdentification>& peptide_identifications, Real p = 0.05) throw (Exception::ParseError);

    protected:

   };

} //namespace OpenMS

#endif // OPENMS_FORMAT_MASCOTOUTFILE_H
