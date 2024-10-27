#include "ProjectOrthoDataPointsFilter.h"
#include <pointmatcher/Parametrizable.h>
#include <iostream>

template<typename T>
ProjectOrthoDataPointsFilter<T>::ProjectOrthoDataPointsFilter() :
    PointMatcher<T>::DataPointsFilter(),
    zPlane(PointMatcherSupport::Parametrizable::get<T>("zPlane"))
{
    std::cout << "Using ProjectOrthoDataPointsFilter with zPlane=" << zPlane << std::endl;
}

template<typename T>
typename PointMatcher<T>::DataPoints ProjectOrthoDataPointsFilter<T>::filter(const typename PointMatcher<T>::DataPoints& input)
{
    typename PointMatcher<T>::DataPoints output(input);
    inPlaceFilter(output);
    return output;
}

template<typename T>
void ProjectOrthoDataPointsFilter<T>::inPlaceFilter(typename PointMatcher<T>::DataPoints& cloud)
{
    const int nbPointsIn = cloud.features.cols();
    using DataPoints = typename PointMatcher<T>::DataPoints;
    using Label = typename DataPoints::Label;
    using Labels = typename DataPoints::Labels;

    Labels featLabels;
    featLabels.push_back(Label("x", 1));
    featLabels.push_back(Label("y", 1));
    featLabels.push_back(Label("pad", 1));

    Labels descLabels;

    DataPoints cloud_filtered(featLabels, descLabels, nbPointsIn);

    for (int i = 0; i < nbPointsIn; ++i)
    {
        cloud_filtered.features(0, i) = cloud.features(0, i);
        cloud_filtered.features(1, i) = cloud.features(1, i);
        cloud_filtered.features(2, i) = 1;
    }

    PointMatcher<T>::swapDataPoints(cloud, cloud_filtered);
}

// Description method for the filter
template<typename T>
const std::string ProjectOrthoDataPointsFilter<T>::description()
{
    return "Projects 3D points onto a specified z-plane, creating a 2D point cloud.";
}

// Explicit template instantiation for float and double
template class ProjectOrthoDataPointsFilter<float>;
template class ProjectOrthoDataPointsFilter<double>;
