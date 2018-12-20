#include "utilities/titandb/blob_format.h"
#include "util/testharness.h"
#include "utilities/titandb/util.h"

namespace rocksdb {
namespace titandb {

class BlobFormatTest : public testing::Test {};

TEST(BlobFormatTest, BlobRecord) {
  BlobRecord input;
  CheckCodec(input);
  input.key = "hello";
  input.value = "world";
  CheckCodec(input);
}

TEST(BlobFormatTest, BlobHandle) {
  BlobHandle input;
  CheckCodec(input);
  input.offset = 2;
  input.size = 3;
  CheckCodec(input);
}

TEST(BlobFormatTest, BlobIndex) {
  BlobIndex input;
  CheckCodec(input);
  input.file_number = 1;
  input.blob_handle.offset = 2;
  input.blob_handle.size = 3;
  CheckCodec(input);
}

TEST(BlobFormatTest, BlobFileMeta) {
  BlobFileMeta input(2, 3);
  CheckCodec(input);
}

TEST(BlobFormatTest, BlobFileFooter) {
  BlobFileFooter input;
  CheckCodec(input);
  input.meta_index_handle.set_offset(123);
  input.meta_index_handle.set_size(321);
  CheckCodec(input);
}

}  // namespace titandb
}  // namespace rocksdb

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
