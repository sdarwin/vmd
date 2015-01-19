#if !defined(BOOST_VMD_DETAIL_NUMBER_EQUAL_HPP)
#define BOOST_VMD_DETAIL_NUMBER_EQUAL_HPP

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/logical/bitand.hpp>
#include <boost/preprocessor/logical/compl.hpp>
#include <boost/vmd/detail/is_number.hpp>

/*

	Check if the types are both numbers

*/

#define BOOST_VMD_DETAIL_NUMBER_EQUAL(nmf,nms) \
	BOOST_VMD_IDENTITY_RESULT \
		( \
		BOOST_PP_IIF \
			( \
			BOOST_PP_BITAND \
				( \
				BOOST_VMD_DETAIL_IS_NUMBER(nmf), \
				BOOST_VMD_DETAIL_IS_NUMBER(nms) \
				), \
			BOOST_PP_EQUAL, \
			BOOST_VMD_IDENTITY(0) \
			) \
		(nmf,nms) \
		) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_NOT_EQUAL(nmf,nms) \
	BOOST_PP_COMPL \
		( \
		BOOST_VMD_DETAIL_NUMBER_EQUAL(nmf,nms) \
		) \
/**/

#endif /* BOOST_VMD_DETAIL_NUMBER_EQUAL_HPP */
