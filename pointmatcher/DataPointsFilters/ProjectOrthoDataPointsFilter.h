#pragma once

#include "PointMatcher.h"

template <typename T>
class ProjectOrthoDataPointsFilter : public PointMatcher<T>::DataPointsFilter {
public:
  // Constructor
  typedef PointMatcherSupport::Parametrizable P;
  typedef P::Parameters Parameters;
  typedef P::ParameterDoc ParameterDoc;
  typedef P::ParametersDoc ParametersDoc;

  ProjectOrthoDataPointsFilter();

  // Filter functions
  typename PointMatcher<T>::DataPoints
  filter(const typename PointMatcher<T>::DataPoints &input) override;
  void inPlaceFilter(typename PointMatcher<T>::DataPoints &cloud) override;

  // Required methods
  static const std::string description();
  // static const std::string availableParameters();

private:
  T zPlane; // z-plane for 2D projection
};
