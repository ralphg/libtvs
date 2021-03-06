#
# Copyright (c) 2017 OFFIS Institute for Information Technology
#                          Oldenburg, Germany
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

subdir('extern')

internal_deps = []

units_sources = files(
  'units/common_impl.cpp',
  )

internal_deps += declare_dependency(include_directories: proj_includes,
                                    sources: units_sources)

units_headers = files(
  'units/common.h',
  'units/sc_time.h',
  'units/sc_trace.h',
  'units/time.h',
  'units/common_impl.tpp',
  )

install_headers(units_headers, subdir : 'tvs/units')


utils_sources = files(
  'utils/report/message.cpp',
  'utils/report/report_base.cpp',
  'utils/variant.cpp',
  'utils/variant_traits.cpp',
  )

internal_deps += declare_dependency(include_directories: proj_includes,
                                    sources: utils_sources)

utils_headers =  files(
  'utils/assert.h',
  'utils/boost.h',
  'utils/debug.h',
  'utils/macros.h',
  'utils/noncopyable.h',
  'utils/systemc.h',
  'utils/type_id.h',
  'utils/unique_ptr.h',
  'utils/report.h',
  'utils/report_msgs.h',
  'utils/variant.h',
  'utils/variant_traits.h',
  )

install_headers(utils_headers, subdir : 'tvs/utils')


report_headers = files(
  'utils/report/macros_def.h',
  'utils/report/macros_undef.h',
  'utils/report/report_base.h',
  'utils/report/report_msgs.h',
  'utils/report/message.h',
  )

install_headers(report_headers, subdir : 'tvs/utils/report')


tracing_sources = files(
  'tracing/timed_duration.cpp',
  'tracing/timed_object.cpp',
  'tracing/timed_reader_base.cpp',
  'tracing/timed_stream_base.cpp',
  'tracing/timed_writer_base.cpp',
  )

tracing_headers = files(
  'tracing/timed_duration.h',
  'tracing/timed_object.h',
  'tracing/timed_ranges.h',
  'tracing/timed_reader_base.h',
  'tracing/timed_reader.h',
  'tracing/timed_sequence.h',
  'tracing/timed_sequence.tpp',
  'tracing/timed_stream_base.h',
  'tracing/timed_stream.h',
  'tracing/timed_stream.tpp',
  'tracing/timed_stream_policies.h',
  'tracing/timed_stream_policies.tpp',
  'tracing/timed_stream_processor_base.h',
  'tracing/timed_stream_traits.h',
  'tracing/timed_value.h',
  'tracing/timed_variant.h',
  'tracing/timed_writer_base.h',
  'tracing/timed_writer.h',
  )

install_headers(tracing_headers, subdir : 'tvs/tracing')
install_headers('tracing.h',     subdir : 'tvs')


tracing_lib = library('tvs', tracing_sources,
                      dependencies : [proj_deps, internal_deps],
                      include_directories : proj_includes,
                      install : true,
                      version : meson.project_version())

