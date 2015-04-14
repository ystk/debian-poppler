#include <poppler.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  PopplerDocument* doc;
  int n_pages;

  if (argc < 2)
    return EXIT_FAILURE;

#if !defined(GLIB_VERSION_2_36)
  g_type_init();
#endif
  doc = poppler_document_new_from_file(argv[1], NULL, NULL);
  g_assert(doc != NULL);

  n_pages = poppler_document_get_n_pages(doc);
  g_assert_cmpint(n_pages, > , 0);

  g_object_unref(doc);
  return EXIT_SUCCESS;
}
