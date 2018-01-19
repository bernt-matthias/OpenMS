// --------------------------------------------------------------------------
//                   OpenMS -- Open-Source Mass Spectrometry
// --------------------------------------------------------------------------
// Copyright The OpenMS Team -- Eberhard Karls University Tuebingen,
// ETH Zurich, and Freie Universitaet Berlin 2002-2017.
//
// This software is released under a three-clause BSD license:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of any author or any participating institution
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// For a full list of authors, refer to the file AUTHORS.
// --------------------------------------------------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ANY OF THE AUTHORS OR THE CONTRIBUTING
// INSTITUTIONS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// --------------------------------------------------------------------------
// $Maintainer: Hendrik Weisser $
// $Authors: Hendrik Weisser $
// --------------------------------------------------------------------------

#ifndef OPENMS_METADATA_IDENTIFICATIONDATA_H
#define OPENMS_METADATA_IDENTIFICATIONDATA_H

#include <OpenMS/METADATA/IdentificationData_MetaData.h>
#include <OpenMS/METADATA/IdentificationData_ParentMolecule.h>
#include <OpenMS/METADATA/IdentificationData_IdentifiedMolecule.h>
#include <OpenMS/METADATA/IdentificationData_DataQuery.h>
#include <OpenMS/FORMAT/MzTab.h>
#include <OpenMS/METADATA/PeptideIdentification.h>
#include <OpenMS/METADATA/ProteinIdentification.h>

namespace OpenMS
{
  class OPENMS_DLLAPI IdentificationData: public MetaInfoInterface
  {
  public:

    // types:
    using MoleculeType = IdentificationDataInternal::MoleculeType;
    using MassType = IdentificationDataInternal::MassType;

    using InputFiles = IdentificationDataInternal::InputFiles;
    using InputFileRef = IdentificationDataInternal::InputFileRef;

    using DataProcessingSoftware =
      IdentificationDataInternal::DataProcessingSoftware;
    using ProcessingSoftwareRef =
      IdentificationDataInternal::ProcessingSoftwareRef;

    using DataProcessingStep = IdentificationDataInternal::DataProcessingStep;
    using DataProcessingSteps = IdentificationDataInternal::DataProcessingSteps;
    using ProcessingStepRef = IdentificationDataInternal::ProcessingStepRef;

    using DBSearchParam = IdentificationDataInternal::DBSearchParam;
    using DBSearchParams = IdentificationDataInternal::DBSearchParams;
    using SearchParamRef = IdentificationDataInternal::SearchParamRef;
    using DBSearchSteps = IdentificationDataInternal::DBSearchSteps;

    using ScoreType = IdentificationDataInternal::ScoreType;
    using ScoreTypes = IdentificationDataInternal::ScoreTypes;
    using ScoreTypeRef = IdentificationDataInternal::ScoreTypeRef;
    using ScoreList = IdentificationDataInternal::ScoreList;

    using DataQuery = IdentificationDataInternal::DataQuery;
    using DataQueries = IdentificationDataInternal::DataQueries;
    using DataQueryRef = IdentificationDataInternal::DataQueryRef;

    using ParentMolecule = IdentificationDataInternal::ParentMolecule;
    using ParentMolecules = IdentificationDataInternal::ParentMolecules;
    using ParentMoleculeRef = IdentificationDataInternal::ParentMoleculeRef;

    using MoleculeParentMatch = IdentificationDataInternal::MoleculeParentMatch;
    using ParentMatches = IdentificationDataInternal::ParentMatches;

    using IdentifiedPeptide = IdentificationDataInternal::IdentifiedPeptide;
    using IdentifiedPeptides = IdentificationDataInternal::IdentifiedPeptides;
    using IdentifiedPeptideRef =
      IdentificationDataInternal::IdentifiedPeptideRef;

    using IdentifiedCompound = IdentificationDataInternal::IdentifiedCompound;
    using IdentifiedCompounds = IdentificationDataInternal::IdentifiedCompounds;
    using IdentifiedCompoundRef =
      IdentificationDataInternal::IdentifiedCompoundRef;

    using IdentifiedOligo = IdentificationDataInternal::IdentifiedOligo;
    using IdentifiedOligos = IdentificationDataInternal::IdentifiedOligos;
    using IdentifiedOligoRef = IdentificationDataInternal::IdentifiedOligoRef;

    using PeakAnnotations = IdentificationDataInternal::PeakAnnotations;
    using IdentifiedMoleculeRef =
      IdentificationDataInternal::IdentifiedMoleculeRef;

    using MoleculeQueryMatch = IdentificationDataInternal::MoleculeQueryMatch;
    using MoleculeQueryMatches =
      IdentificationDataInternal::MoleculeQueryMatches;
    using QueryMatchRef = IdentificationDataInternal::QueryMatchRef;


    /// Default constructor
    IdentificationData():
      current_step_ref_(processing_steps_.end())
    {
    }

    // Copy constructor - not allowed, as references would be invalidated:
    IdentificationData(const IdentificationData& other) = delete;

    /// Move constructor
    IdentificationData(IdentificationData&& other):
      current_step_ref_(other.current_step_ref_)
    {
      input_files_.swap(other.input_files_);
      processing_software_.swap(other.processing_software_);
      processing_steps_.swap(other.processing_steps_);
      db_search_params_.swap(other.db_search_params_);
      db_search_steps_.swap(other.db_search_steps_);
      score_types_.swap(other.score_types_);
      data_queries_.swap(other.data_queries_);
      parent_molecules_.swap(other.parent_molecules_);
      identified_peptides_.swap(other.identified_peptides_);
      identified_compounds_.swap(other.identified_compounds_);
      identified_oligos_.swap(other.identified_oligos_);
      query_matches_.swap(other.query_matches_);
    }

    InputFileRef registerInputFile(const String& file);

    ProcessingSoftwareRef registerDataProcessingSoftware(
      const Software& software);

    SearchParamRef registerDBSearchParam(const DBSearchParam& param);

    ProcessingStepRef registerDataProcessingStep(const DataProcessingStep&
                                                 step);

    ProcessingStepRef registerDataProcessingStep(
      const DataProcessingStep& step, SearchParamRef search_ref);

    ScoreTypeRef registerScoreType(const ScoreType& score);

    DataQueryRef registerDataQuery(const DataQuery& query);

    ParentMoleculeRef registerParentMolecule(const ParentMolecule& parent);

    IdentifiedPeptideRef registerIdentifiedPeptide(const IdentifiedPeptide&
                                                   peptide);

    IdentifiedCompoundRef registerIdentifiedCompound(const IdentifiedCompound&
                                                     compound);

    IdentifiedOligoRef registerIdentifiedOligo(const IdentifiedOligo& oligo);

    QueryMatchRef registerMoleculeQueryMatch(const MoleculeQueryMatch& match);

    const InputFiles& getInputFiles() const
    {
      return input_files_;
    }

    const DataProcessingSoftware& getDataProcessingSoftware() const
    {
      return processing_software_;
    }

    const DataProcessingSteps& getDataProcessingSteps() const
    {
      return processing_steps_;
    }

    const DBSearchParams& getDBSearchParams() const
    {
      return db_search_params_;
    }

    const DBSearchSteps& getDBSearchSteps() const
    {
      return db_search_steps_;
    }

    const ScoreTypes& getScoreTypes() const
    {
      return score_types_;
    }

    const DataQueries& getDataQueries() const
    {
      return data_queries_;
    }

    const ParentMolecules& getParentMolecules() const
    {
      return parent_molecules_;
    }

    const IdentifiedPeptides& getIdentifiedPeptides() const
    {
      return identified_peptides_;
    }

    const IdentifiedCompounds& getIdentifiedCompounds() const
    {
      return identified_compounds_;
    }

    const IdentifiedOligos& getIdentifiedOligos() const
    {
      return identified_oligos_;
    }

    const MoleculeQueryMatches& getMoleculeQueryMatches() const
    {
      return query_matches_;
    }

    void addScore(QueryMatchRef match_ref, ScoreTypeRef score_ref,
                  double value);


    /*!
      @brief Set a data processing step that will apply to all subsequent "register..." calls.

      This step will be appended to the list of processing steps for all relevant elements that are registered subsequently (unless it is already the last entry in the list).
      If a score type without a software reference is registered, the software reference of this processing step will be applied.

      Effective until @ref clearCurrentProcessingStep() is called.
     */
    void setCurrentProcessingStep(ProcessingStepRef step_ref);

    /*!
      Return the current processing step (set via @ref setCurrentProcessingStep()).

      If no current processing step has been set, @p processing_steps.end() is returned.
    */
    ProcessingStepRef getCurrentProcessingStep();

    /// Cancel the effect of @ref setCurrentProcessingStep().
    void clearCurrentProcessingStep();

    std::vector<QueryMatchRef> getBestMatchPerQuery(ScoreTypeRef
                                                    score_ref) const;

    ScoreTypeRef findScoreType(const String& score_name) const;

    ScoreTypeRef findScoreType(const String& score_name,
                               ProcessingSoftwareRef software_ref) const;

    /// Helper function to compare two scores
    static bool isBetterScore(double first, double second, bool higher_better)
    {
      if (higher_better) return first > second;
      return first < second;
    }

  protected:

    // containers:
    InputFiles input_files_;
    DataProcessingSoftware processing_software_;
    DataProcessingSteps processing_steps_;
    DBSearchParams db_search_params_;
    // @TODO: store SearchParamRef inside ProcessingStep? (may not be required
    // for many processing steps)
    DBSearchSteps db_search_steps_;
    ScoreTypes score_types_;
    DataQueries data_queries_;
    ParentMolecules parent_molecules_;
    IdentifiedPeptides identified_peptides_;
    IdentifiedCompounds identified_compounds_;
    IdentifiedOligos identified_oligos_;
    MoleculeQueryMatches query_matches_;

    /// Reference to the current data processing step (see @ref setCurrentProcessingStep())
    ProcessingStepRef current_step_ref_;

    /// Helper function to check if all score types are valid
    void checkScoreTypes_(const ScoreList& scores);

    /// Helper function to check if all processing steps are valid
    void checkProcessingSteps_(const std::vector<ProcessingStepRef>& step_refs);

    /// Helper function to check if all parent matches are valid
    void checkParentMatches_(const ParentMatches& matches,
                             MoleculeType expected_type);

    /// Helper functor for augmenting entries (derived from ScoredProcessingResult) in a @t boost::multi_index_container structure
    template <typename ElementType>
    struct ModifyMultiIndexMergeElements
    {
      ModifyMultiIndexMergeElements(const ElementType& update):
        update(update)
      {
      }

      void operator()(ElementType& element)
      {
        element += update;
      }

      const ElementType& update;
    };

    /*!
      Helper functor for adding processing steps to elements in a @t boost::multi_index_container structure

      The validity of the processing step reference cannot be checked here!
    */
    template <typename ElementType>
    struct ModifyMultiIndexAddProcessingStep
    {
      ModifyMultiIndexAddProcessingStep(ProcessingStepRef step_ref):
        step_ref(step_ref)
      {
      }

      void operator()(ElementType& element)
      {
        if (element.processing_step_refs.empty() ||
            (element.processing_step_refs.back() != step_ref))
        {
          element.processing_step_refs.push_back(step_ref);
        }
      }

      ProcessingStepRef step_ref;
    };

    /*!
      Helper functor for adding scores to elements in a @t boost::multi_index_container structure

      The validity of the score type reference cannot be checked here!
    */
    template <typename ElementType>
    struct ModifyMultiIndexAddScore
    {
      ModifyMultiIndexAddScore(ScoreTypeRef score_type_ref, double value):
        score_type_ref(score_type_ref), value(value)
      {
      }

      void operator()(ElementType& element)
      {
        // @TODO: add checks?
        element.scores.push_back(make_pair(score_type_ref, value));
      }

      ScoreTypeRef score_type_ref;
      double value;
    };

    /// Helper function for adding entries (derived from ScoredProcessingResult) to a @t boost::multi_index_container structure
    template <typename ContainerType, typename ElementType>
    typename ContainerType::iterator insertIntoMultiIndex_(
      ContainerType& container, const ElementType& element)
    {
      checkScoreTypes_(element.scores);
      checkProcessingSteps_(element.processing_step_refs);

      auto result = container.insert(element);
      if (!result.second) // existing element - merge in new information
      {
        ModifyMultiIndexMergeElements<ElementType> modifier(element);
        container.modify(result.first, modifier);
      }

      // add current processing step (if necessary):
      if (current_step_ref_ != processing_steps_.end())
      {
        ModifyMultiIndexAddProcessingStep<ElementType>
          modifier(current_step_ref_);
        container.modify(result.first, modifier);
      }

      return result.first;
    }

    /// Check whether a pointer references an element in a container
    template <typename RefType, typename ContainerType>
    bool isValidReference_(RefType ref, const ContainerType& container)
    {
      for (auto it = container.begin(); it != container.end(); ++it)
      {
        if (ref == it) return true;
      }
      return false;
    }


    // IDFilter needs access to do its job:
    friend class IDFilter;
  };
}

#endif
