//******************************************************************************
// Copyright (C) 1999 Jim Wanner and the SourceMonitor team.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//******************************************************************************

#pragma once

#include <filesystem>
#include <fstream>
#include <unordered_map>
#include "project.h"

namespace smos
{
    namespace smcore
    {
        class ArchiveReader
        {
        public:
            ArchiveReader(std::ifstream& p_stream) : m_stream(p_stream) { }
            template<typename T> T Read();
            unsigned int ReadCount();

        private:
            unsigned int ReadStringLength();

            std::ifstream& m_stream;
            unsigned int m_classesIndex = 1;
            std::unordered_map<unsigned int, std::string> m_classes;

        protected:
        };

        class SMLanguageReader
        {
        public:
            SMLanguageReader(ArchiveReader& archiveReader) : m_archiveReader(archiveReader) { }
            void Read();

        private:
            ArchiveReader& m_archiveReader;
        };

        class SMCheckpointsReader
        {
        public:
            SMCheckpointsReader(ArchiveReader& archiveReader) : m_archiveReader(archiveReader) { }
            void Read();

        private:
            ArchiveReader& m_archiveReader;
        };

        class SMPReader
        {
        public:
            SMPReader() = default;
            ~SMPReader();
            bool Open(std::filesystem::path path);
            bool Read(Project& project);

        protected:
            std::ifstream m_stream;
        };

        struct ClassInfo
        {
            std::string m_name;
        };
    }
}
