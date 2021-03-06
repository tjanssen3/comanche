/*
   Copyright [2018] [IBM Corporation]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef _FD_SOCKET_H_
#define _FD_SOCKET_H_

#include <cstddef> /* size_t */

class Fd_socket
{
  int _fd;
  void close() noexcept;
public:
  Fd_socket();
  explicit Fd_socket(int fd_);
  ~Fd_socket();
  Fd_socket(const Fd_socket &) = delete;
  Fd_socket &operator=(const Fd_socket &) = delete;
  Fd_socket(Fd_socket &&) noexcept;
  Fd_socket &operator=(Fd_socket &&) noexcept;
  void send(const void *buf, std::size_t size) const;
  void recv(void *buf, std::size_t size) const;
  int fd() const { return _fd; }
  bool good() const  { return _fd != -1; }
  operator bool() const  { return good(); }
};

#endif
