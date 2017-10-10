#ifndef BTT2_TEST_H
#define BTT2_TEST_H

#include <stdbool.h>

  void make_header();

  void make_footer();

  void make_test_title(char *);

  void assert(bool, char *);

  void end_test_title(char *);

#endif
