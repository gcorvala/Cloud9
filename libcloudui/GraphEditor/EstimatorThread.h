#ifndef __ESTIMATOR_THREAD_H__
#define __ESTIMATOR_THREAD_H__

#include <QThread>
#include <libcloud/2D/Estimator.h>

template <typename InputType, typename OutputType>
class EstimatorThread : public QThread {
  public:
    EstimatorThread (QObject* parent = 0);
    virtual ~EstimatorThread ();

    void run ();

    void setInput (InputType* _input);
    OutputType* getOutput () const;

  protected:
    Estimator<InputType, OutputType>* estimator;
    Matrix<InputType>* input;
    Matrix<OutputType> output;
};

template <typename InputType, typename OutputType>
EstimatorThread<InputType, OutputType>::EstimatorThread (QObject* parent)
  :QThread(parent)
{
}

template <typename InputType, typename OutputType>
EstimatorThread<InputType, OutputType>::~EstimatorThread ()
{
}

template <typename InputType, typename OutputType>
void
EstimatorThread<InputType, OutputType>::run ()
{
  estimator->compute (*input, output);
}

template <typename InputType, typename OutputType>
void
EstimatorThread<InputType, OutputType>::setInput (InputType* _input)
{
  input = _input;
}

template <typename InputType, typename OutputType>
OutputType*
EstimatorThread<InputType, OutputType>::getOutput () const
{
  return output;
}

#endif