// Copyright 2024 Musaev Ilgar

#include <gtest/gtest.h>

#include "omp/musaev_i_sort_double_batcher/include/ops_omp.hpp"

TEST(musaev_i_sort_double_batcher, array) {
  // Create data
  std::vector<double> array = {4.44, 8.88, 1.11, 2.22, 9.99, 6.66, 5.55, 3.33, 7.77};
  // Create data
  std::vector<double> out_seq(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataSeq = std::make_shared<ppc::core::TaskData>();
  MIBDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataSeq->inputs_count.emplace_back(array.size());
  MIBDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_seq.data()));
  MIBDataSeq->outputs_count.emplace_back(out_seq.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherSequential testMISBSequential(MIBDataSeq);
  ASSERT_EQ(testMISBSequential.validation(), true);
  testMISBSequential.pre_processing();
  testMISBSequential.run();
  testMISBSequential.post_processing();

  // Create data
  std::vector<double> out_par(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataOmp = std::make_shared<ppc::core::TaskData>();
  MIBDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataOmp->inputs_count.emplace_back(array.size());
  MIBDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_par.data()));
  MIBDataOmp->outputs_count.emplace_back(out_par.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherOmpParallel testMISBompParallel(MIBDataOmp);
  ASSERT_EQ(testMISBompParallel.validation(), true);
  testMISBompParallel.pre_processing();
  testMISBompParallel.run();
  testMISBompParallel.post_processing();

  for (size_t i = 0; i < out_seq.size(); ++i) {
    ASSERT_EQ(out_seq[i], out_par[i]);
  }
}

TEST(musaev_i_sort_double_batcher, test_array_2) {
  // Create data
  std::vector<double> array = {67.1234, 29.567,  83.9876, 14.70,   95.345,  42.245,  55.678,  78.3456, 6.801,
                               37.8765, 20.4567, 51.245,  71.8765, 1.3456,  63.2345, 88.8,    46.7890, 22.1234,
                               5.89,    8.3456,  33.7890, 17.2345, 91.5678, 59.1234, 25.6789, 69.346,  8.7890,
                               40.1234, 80.5678, 52.3456, 16.7890, 93.2345, 74.5678, 38.12,   9.356,   31.7890,
                               86.235,  12.5678, 64.123,  44.5678, 77.2345, 35.5678, 89.7890, 68.234,  26.5678,
                               56.234,  3.5678,  70.7890, 18.134,  49.5678};
  // Create data
  std::vector<double> out_seq(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataSeq = std::make_shared<ppc::core::TaskData>();
  MIBDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataSeq->inputs_count.emplace_back(array.size());
  MIBDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_seq.data()));
  MIBDataSeq->outputs_count.emplace_back(out_seq.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherSequential testMISBSequential(MIBDataSeq);
  ASSERT_EQ(testMISBSequential.validation(), true);
  testMISBSequential.pre_processing();
  testMISBSequential.run();
  testMISBSequential.post_processing();

  // Create data
  std::vector<double> out_par(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataOmp = std::make_shared<ppc::core::TaskData>();
  MIBDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataOmp->inputs_count.emplace_back(array.size());
  MIBDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_par.data()));
  MIBDataOmp->outputs_count.emplace_back(out_par.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherOmpParallel testMISBompParallel(MIBDataOmp);
  ASSERT_EQ(testMISBompParallel.validation(), true);
  testMISBompParallel.pre_processing();
  testMISBompParallel.run();
  testMISBompParallel.post_processing();

  for (size_t i = 0; i < out_seq.size(); ++i) {
    ASSERT_EQ(out_seq[i], out_par[i]);
  }
}
TEST(musaev_i_sort_double_batcher, test_empty) {
  // Create data
  std::vector<double> array = {};
  // Create data
  std::vector<double> out_seq(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataSeq = std::make_shared<ppc::core::TaskData>();
  MIBDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataSeq->inputs_count.emplace_back(array.size());
  MIBDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_seq.data()));
  MIBDataSeq->outputs_count.emplace_back(out_seq.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherSequential testMISBSequential(MIBDataSeq);
  ASSERT_EQ(testMISBSequential.validation(), true);
  testMISBSequential.pre_processing();
  testMISBSequential.run();
  testMISBSequential.post_processing();

  // Create data
  std::vector<double> out_par(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataOmp = std::make_shared<ppc::core::TaskData>();
  MIBDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataOmp->inputs_count.emplace_back(array.size());
  MIBDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_par.data()));
  MIBDataOmp->outputs_count.emplace_back(out_par.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherOmpParallel testMISBompParallel(MIBDataOmp);
  ASSERT_EQ(testMISBompParallel.validation(), true);
  testMISBompParallel.pre_processing();
  testMISBompParallel.run();
  testMISBompParallel.post_processing();

  for (size_t i = 0; i < out_seq.size(); ++i) {
    ASSERT_EQ(out_seq[i], out_par[i]);
  }
}
TEST(musaev_i_sort_double_batcher, test_one_number) {
  // Create data
  std::vector<double> array = {1};
  // Create data
  std::vector<double> out_seq(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataSeq = std::make_shared<ppc::core::TaskData>();
  MIBDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataSeq->inputs_count.emplace_back(array.size());
  MIBDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_seq.data()));
  MIBDataSeq->outputs_count.emplace_back(out_seq.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherSequential testMISBSequential(MIBDataSeq);
  ASSERT_EQ(testMISBSequential.validation(), true);
  testMISBSequential.pre_processing();
  testMISBSequential.run();
  testMISBSequential.post_processing();

  // Create data
  std::vector<double> out_par(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataOmp = std::make_shared<ppc::core::TaskData>();
  MIBDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataOmp->inputs_count.emplace_back(array.size());
  MIBDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_par.data()));
  MIBDataOmp->outputs_count.emplace_back(out_par.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherOmpParallel testMISBompParallel(MIBDataOmp);
  ASSERT_EQ(testMISBompParallel.validation(), true);
  testMISBompParallel.pre_processing();
  testMISBompParallel.run();
  testMISBompParallel.post_processing();

  for (size_t i = 0; i < out_seq.size(); ++i) {
    ASSERT_EQ(out_seq[i], out_par[i]);
  }
}
TEST(musaev_i_sort_double_batcher, test_with_negative) {
  // Create data
  std::vector<double> array = {1.1, -11.1, 5.5, 5, 5.3, 9.9, -6.6, 0, 3.3, 0, -1.1, 15, -2};
  // Create data
  std::vector<double> out_seq(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataSeq = std::make_shared<ppc::core::TaskData>();
  MIBDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataSeq->inputs_count.emplace_back(array.size());
  MIBDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_seq.data()));
  MIBDataSeq->outputs_count.emplace_back(out_seq.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherSequential testMISBSequential(MIBDataSeq);
  ASSERT_EQ(testMISBSequential.validation(), true);
  testMISBSequential.pre_processing();
  testMISBSequential.run();
  testMISBSequential.post_processing();

  // Create data
  std::vector<double> out_par(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataOmp = std::make_shared<ppc::core::TaskData>();
  MIBDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataOmp->inputs_count.emplace_back(array.size());
  MIBDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_par.data()));
  MIBDataOmp->outputs_count.emplace_back(out_par.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherOmpParallel testMISBompParallel(MIBDataOmp);
  ASSERT_EQ(testMISBompParallel.validation(), true);
  testMISBompParallel.pre_processing();
  testMISBompParallel.run();
  testMISBompParallel.post_processing();

  for (size_t i = 0; i < out_seq.size(); ++i) {
    ASSERT_EQ(out_seq[i], out_par[i]);
  }
}

TEST(musaev_i_sort_double_batcher, test_random) {
  // Create data
  std::vector<double> array = MusaevIlgarOmp::randomVector(1000, -1000000, 1000000);
  // Create data
  std::vector<double> out_seq(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataSeq = std::make_shared<ppc::core::TaskData>();
  MIBDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataSeq->inputs_count.emplace_back(array.size());
  MIBDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_seq.data()));
  MIBDataSeq->outputs_count.emplace_back(out_seq.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherSequential testMISBSequential(MIBDataSeq);
  ASSERT_EQ(testMISBSequential.validation(), true);
  testMISBSequential.pre_processing();
  testMISBSequential.run();
  testMISBSequential.post_processing();

  // Create data
  std::vector<double> out_par(array.size());

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> MIBDataOmp = std::make_shared<ppc::core::TaskData>();
  MIBDataOmp->inputs.emplace_back(reinterpret_cast<uint8_t *>(array.data()));
  MIBDataOmp->inputs_count.emplace_back(array.size());
  MIBDataOmp->outputs.emplace_back(reinterpret_cast<uint8_t *>(out_par.data()));
  MIBDataOmp->outputs_count.emplace_back(out_par.size());

  // Create Task
  MusaevIlgarOmp::RadixSortDoubleBatcherOmpParallel testMISBompParallel(MIBDataOmp);
  ASSERT_EQ(testMISBompParallel.validation(), true);
  testMISBompParallel.pre_processing();
  testMISBompParallel.run();
  testMISBompParallel.post_processing();

  for (size_t i = 0; i < out_seq.size(); ++i) {
    ASSERT_EQ(out_seq[i], out_par[i]);
  }
}
