#pragma once

#include "PointMatcher.h"

template<typename T>
class ProjectOrthoDataPointsFilter : public PointMatcher<T>::DataPointsFilter {
public:
    // Constructor
    ProjectOrthoDataPointsFilter();

    // Filter functions
    typename PointMatcher<T>::DataPoints filter(const typename PointMatcher<T>::DataPoints& input) override;
    void inPlaceFilter(typename PointMatcher<T>::DataPoints& cloud) override;

    // Required methods
    static const std::string description();

private:
    T zPlane; // z-plane for 2D projection
};
