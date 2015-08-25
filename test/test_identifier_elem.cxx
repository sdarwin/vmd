
//  (C) Copyright Edward Diener 2011-2015
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/elem.hpp>
#include <boost/vmd/is_empty.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>
#include <boost/preprocessor/tuple/elem.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS

  #define BOOST_VMD_REGISTER_ggh (ggh)
  #define BOOST_VMD_REGISTER_dvd (dvd)
  #define BOOST_VMD_REGISTER_ccc (ccc)
  #define BOOST_VMD_REGISTER_aname (aname)
  
  #define BOOST_VMD_DETECT_ggh_ggh
  #define BOOST_VMD_DETECT_ccc_ccc
  #define BOOST_VMD_DETECT_aname_aname
  
  #define ANIDENTIFIER ggh
  #define ANIDENTIFIER2 dvd
  #define ANIDENTIFIER3 ccc
  #define ANIDENTIFIER5 aname
  #define ANUMBER 249
  #define ANUMBER2 17
  #define ASEQ (25)(26)(27)
  #define ATUPLE (0,1,2,3,((a,b))((c,d))((e))((f,g,h)))
  #define ALIST (0,(1,(2,(3,BOOST_PP_NIL))))
  #define ANARRAY (3,(a,b,38))
  #define ANARRAY2 (5,(c,d,133,22,15))
  #define ANARRAY3 (5,(ccc,dvd,133,22,15))
  #define ASEQUENCE ANUMBER ALIST ATUPLE ANIDENTIFIER ANARRAY ASEQ
  #define ASEQUENCE2 ANIDENTIFIER2 ANARRAY2 ASEQ ALIST ANUMBER ATUPLE
  #define ASEQUENCE3 ASEQ ANUMBER2 ANIDENTIFIER3 ATUPLE
  #define ASEQUENCE4
  #define ASEQUENCE5 ASEQ ANUMBER ATUPLE ANIDENTIFIER5
  
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(0,ANARRAY,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,ALIST,BOOST_VMD_TYPE_IDENTIFIER)));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(0,ASEQ,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,ANIDENTIFIER3,(ggh,dvd,ccc),BOOST_VMD_TYPE_IDENTIFIER)));
  
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(3,ASEQUENCE,(dvd,ccc,ggh),BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(3,ASEQUENCE,ccc,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(3,ASEQUENCE,(ccc,ggh),BOOST_VMD_TYPE_IDENTIFIER)));
  
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(0,ASEQUENCE2,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,ASEQUENCE2,BOOST_VMD_TYPE_IDENTIFIER)));
  
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(2,ASEQUENCE3,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(3,BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(2,ASEQUENCE3,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))),3);
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(2,ASEQUENCE3,BOOST_VMD_TYPE_IDENTIFIER)));
 
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(0,ASEQUENCE4,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(0,ASEQUENCE4,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(0,ASEQUENCE4,BOOST_VMD_TYPE_IDENTIFIER)));
  
  BOOST_TEST(!BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(3,ASEQUENCE5,aname,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_ELEM(3,ASEQUENCE5,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(3,ASEQUENCE5,(ccc,dvd),BOOST_VMD_TYPE_IDENTIFIER)));
  
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_ELEM(4,ASEQUENCE5,BOOST_VMD_RETURN_AFTER,BOOST_VMD_TYPE_IDENTIFIER))));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(4,ASEQUENCE5,BOOST_VMD_TYPE_IDENTIFIER)));
  
#else

BOOST_ERROR("No variadic macro support");
  
#endif

  return boost::report_errors();
  
  }
