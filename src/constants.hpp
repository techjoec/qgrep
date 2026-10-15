// This file is part of qgrep and is distributed under the MIT license, see LICENSE.md
#pragma once

#define Kb *1024
#define Mb Kb Kb

// Approximate uncompressed total size of the chunk
const size_t kChunkSize = 512 Kb;

// Total amount of chunk data in flight
const size_t kMaxQueuedChunkData = 256 Mb;

// Total amount of buffered output in flight
const size_t kMaxBufferedOutput = 32 Mb;

// Flush buffered output from the current chunk after reaching this threshold, if possible
const size_t kBufferedOutputFlushThreshold = 32 Kb;

// File list compression level, 0-9. Must stay >= 3: lz4 1.10 routes levels 1-2
// to LZ4MID, whose no-match skip step grows with the distance since the last
// encoded match (lz4hc.c, "skip faster over incompressible data"). The file
// table opens with the incompressible per-file entry array, so by the end of it
// the step is tens of KB, every later probe misses LZ4's 64 KB window, and the
// whole path buffer comes out as literals.
const int kFileListCompressionLevel = 3;

// File data compression level, 0-9
const int kFileDataCompressionLevel = 3;

// Wait for several seconds before writing changes to amortize writes when many changes are done at once
const int kWatchWriteDeadline = 1;

// Wait for many seconds before launching an update to minimize the chance of concurrent work
const int kWatchUpdateTimeout = 60;

// When we're above a certain threshold of changed files, automatically update
const int kWatchUpdateThresholdFiles = 100;

#undef Mb
#undef Kb