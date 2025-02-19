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

#include "testrunner.h"

#include "test_about.h"
#include "test_license.h"
#include "test_options.h"
#include "test_project.h"
#include "test_version.h"
#include "test_smpreader.h"

// QTEST_MAIN(smos::smtest::TestLicense)

int main(int argc, char *argv[])
{

    int status = 0;

    RUN_TESTS(smos::smtest::TestAbout, argc, argv, &status);
    RUN_TESTS(smos::smtest::TestLicense, argc, argv, &status);
    RUN_TESTS(smos::smtest::TestOptions, argc, argv, &status);
    RUN_TESTS(smos::smtest::TestProject, argc, argv, &status);
    RUN_TESTS(smos::smtest::TestVersion, argc, argv, &status);
    RUN_TESTS(smos::smtest::TestSMPReader, argc, argv, &status);

    return status;
}
