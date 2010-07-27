//-*****************************************************************************
//
// Copyright (c) 2009-2010,
//  Sony Pictures Imageworks, Inc. and
//  Industrial Light & Magic, a division of Lucasfilm Entertainment Company Ltd.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Sony Pictures Imageworks, nor
// Industrial Light & Magic nor the names of their contributors may be used
// to endorse or promote products derived from this software without specific
// prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//-*****************************************************************************

#ifndef _Alembic_TakoAbstract_SubDReader_h_
#define _Alembic_TakoAbstract_SubDReader_h_

#include <Alembic/TakoAbstract/Foundation.h>
#include <Alembic/TakoAbstract/GenMeshReader.h>

namespace Alembic {

namespace TakoAbstract {

namespace TAKO_ABSTRACT_LIB_VERSION_NS {

//-*****************************************************************************
class SubDReader : public GenMeshReader
{
public:
    // Enum inherited from GenMeshNode
    virtual ~SubDReader();

    virtual int getFaceVaryingInterpolateBoundary() = 0;
    virtual int getFaceVaryingPropagateCorners() = 0;
    virtual int getInterpolateBoundary() = 0;

    virtual const std::vector<index_t> & getHolePolyIndices() = 0;

    virtual const std::vector<float> & getCreaseSharpness() = 0;
    virtual const std::vector<index_t> & getCreaseIndices() = 0;
    virtual const std::vector<index_t> & getCreaseLengths() = 0;

    virtual const std::vector<index_t> & getCornerIndices() = 0;
    virtual const std::vector<float> & getCornerSharpness() = 0;

    // Turn off normals
    virtual const std::vector<float> & getNormals(); // Returns 0-length vec.
    virtual bool hasNormals() const { return false; }

    // Be a SubD
    virtual bool isSubD() const { return true; }
};

} // End namespace TAKO_ABSTRACT_LIB_VERSION_NS

} // End namespace TakoAbstract

} // End namespace Alembic

#endif  // _Alembic_TakoAbstract_SubDReader_h_