/*
 * Copyright (c) 2017 OFFIS Institute for Information Technology
 *                          Oldenburg, Germany
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file   timed_writer.h
 * \author Philipp A. Hartmann <pah@computer.org>
 * \brief  timed value writer for tracing (implementation)
 * \see    timed_stream.h
 */

#ifndef TVS_TIMED_WRITER_BASE_H_INCLUDED_
#define TVS_TIMED_WRITER_BASE_H_INCLUDED_

#include "tvs/tracing/timed_object.h"
#include "tvs/tracing/timed_stream_base.h"

namespace tracing {

enum writer_mode
{
  STREAM_ATTACH = 0x1,
  STREAM_CREATE = 0x2,
  STREAM_AUTO = STREAM_ATTACH | STREAM_CREATE,
  STREAM_DEFAULT = STREAM_ATTACH
};

class timed_writer_base : public timed_base
{
  friend class timed_stream_base;
  typedef timed_stream_base stream_type;

public:
  const char* name() { return stream_->name(); }

  virtual stream_type& stream() { return *stream_; }
  virtual stream_type const& stream() const { return *stream_; }

  time_type begin_time() const { return stream_->local_time(); }
  time_type end_time() const { return stream_->end_time(); }
  duration_type duration() const { return stream_->duration(); }

  //! commit/sync interface
  //!{
  void commit() { stream_->commit(); }
  void commit(time_type const& until) { stream_->commit(until); }
  void commit(duration_type const& dur) { stream_->commit(dur); }

  time_type sync() { return stream_->sync(); }
  time_type sync(time_type const& until) { return stream_->sync(until); }
  time_type sync(duration_type const& dur) { return stream_->sync(dur); }
  //!}

  virtual ~timed_writer_base();

protected:
  explicit timed_writer_base(stream_type* own_stream = NULL);

  void attach(const char* name);
  void attach(timed_stream_base& stream);
  void detach();

  void check_stream(const char* context);

private:
  stream_type* stream_;
  stream_type* own_stream_;
};

} // namespace tracing

#endif /* TVS_TIMED_WRITER_BASE_H_INCLUDED_ */
/* Taf!
 */
