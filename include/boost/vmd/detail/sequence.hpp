#if !defined(BOOST_VMD_DETAIL_SEQUENCE_HPP)
#define BOOST_VMD_DETAIL_SEQUENCE_HPP

#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/array/push_back.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/comparison/less_equal.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/control/while.hpp>
#include <boost/preprocessor/list/append.hpp>
#include <boost/preprocessor/list/transform.hpp>
#include <boost/preprocessor/logical/bitor.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/push_back.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/to_array.hpp>
#include <boost/preprocessor/seq/to_tuple.hpp>
#include <boost/preprocessor/seq/transform.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/enum.hpp>
#include <boost/preprocessor/tuple/push_back.hpp>
#include <boost/preprocessor/tuple/replace.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/vmd/array.hpp>
#include <boost/vmd/empty.hpp>
#include <boost/vmd/identifier.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/is_begin_tuple.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/list.hpp>
#include <boost/vmd/number.hpp>
#include <boost/vmd/seq.hpp>
#include <boost/vmd/tuple.hpp>
#include <boost/vmd/types.hpp>
#include <boost/vmd/detail/empty_result.hpp>

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT_ELEM 0
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ELEM 1
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM_ELEM 2
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE_ELEM 3
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES_ELEM 4
#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX_ELEM 5

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
	BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state) \
	BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state) \
		BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX_ELEM,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_IS_EMPTY(state) \
	BOOST_VMD_IS_EMPTY \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_FROM_EMPTY(state,ttuple) \
	(ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_SEQ(state,ttuple) \
	BOOST_PP_SEQ_PUSH_BACK(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state),ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_TUPLE(state,ttuple) \
	BOOST_PP_TUPLE_PUSH_BACK(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state),ttuple) \
/**/

// Array

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_2(state,ttuple) \
	BOOST_PP_ARRAY_PUSH_BACK(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state),ttuple) \
/**/

// List

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_3(state,ttuple) \
	BOOST_PP_LIST_APPEND(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state),(ttuple,BOOST_PP_NIL)) \
/**/

// Seq

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_4(state,ttuple) \
	BOOST_PP_IIF \
	 	( \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_IS_EMPTY(state), \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_FROM_EMPTY, \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_SEQ \
	 	) \
	 (state,ttuple) \
/**/

// Tuple

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_5(state,ttuple) \
	BOOST_PP_IIF \
	 	( \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_IS_EMPTY(state), \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_FROM_EMPTY, \
	 	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_TO_TUPLE \
	 	) \
	 (state,ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_GET_NAME(state) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_PROCESS(name,state,ttuple) \
	name(state,ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD(state,ttuple) \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_PROCESS(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD_GET_NAME(state),state,ttuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state) \
		BOOST_PP_TUPLE_ELEM \
			( \
			0, \
			BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state),BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state)) \
			) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE_REENTRANT(state) \
		BOOST_PP_TUPLE_ELEM \
			( \
			1, \
			BOOST_PP_TUPLE_ELEM(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state),BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state)) \
			) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_UNKNOWN(d,state) \
	( \
	, \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD(state,(BOOST_VMD_TYPE_UNKNOWN,BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state))), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state), \
	BOOST_PP_INC(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state)) \
	) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_GET_FULL_TYPE(state) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_TYPE_, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state) \
		) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_PROCESS(state,tuple) \
	( \
	BOOST_PP_TUPLE_ELEM(1,tuple), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD \
		( \
		state, \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_GET_FULL_TYPE(state), \
			BOOST_PP_TUPLE_ELEM(0,tuple) \
			) \
		), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state), \
	BOOST_PP_INC(BOOST_PP_TUPLE_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state))) \
	) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ_SINGLE(tuple) \
	BOOST_PP_EQUAL(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(0,tuple)),1) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_ISEQ(state,tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_GET_FULL_TYPE(state), \
			BOOST_VMD_TYPE_SEQ \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ_SINGLE, \
		BOOST_VMD_IDENTITY(0) \
		) \
	(tuple) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ(state,tuple) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_ISEQ(state,tuple)) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND(state,tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_SEQ(state,tuple), \
		BOOST_VMD_DETAIL_SEQUENCE_INCREMENT_INDEX, \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND_PROCESS \
		) \
	(state,tuple) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_INCREMENT_INDEX(state,tuple) \
	BOOST_PP_TUPLE_REPLACE(state,BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX_ELEM,BOOST_PP_INC(BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state))) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_TUPLE(state,tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_PP_TUPLE_ELEM(0,tuple) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_INCREMENT_INDEX, \
		BOOST_VMD_DETAIL_SEQUENCE_TYPE_FOUND \
		) \
	(state,tuple) \
/**/

#define	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE(d,call,state) \
	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_TUPLE \
		( \
		state, \
		call(BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state)) \
		) \
/**/
	
#define	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_D(d,call,state) \
	BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_TUPLE \
		( \
		state, \
		call(d,BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state)) \
		) \
/**/
	
#define BOOST_VMD_DETAIL_SEQUENCE_GCLRT(state) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_, \
		BOOST_PP_CAT(BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state),_D) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_GCLPL(state) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_GCL(state,rflag) \
	BOOST_PP_IIF \
		( \
		rflag, \
		BOOST_VMD_DETAIL_SEQUENCE_GCLRT, \
		BOOST_VMD_DETAIL_SEQUENCE_GCLPL \
		) \
	(state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_RT_CALL(d,call,state,rflag) \
	BOOST_PP_IIF \
		( \
		rflag, \
		BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE_D, \
		BOOST_VMD_DETAIL_SEQUENCE_TEST_TYPE \
		) \
	(d,call,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_RT(d,state,rflag) \
	BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_RT_CALL \
		( \
		d, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_GCL(state,rflag), \
		state, \
		rflag \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST_RT \
		( \
		d, \
		state, \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_GET_TYPE_REENTRANT(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_OP(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state), \
			BOOST_PP_TUPLE_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state)) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_UNKNOWN, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP_TEST \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_INNER_PRED(d,state) \
	BOOST_PP_NOT_EQUAL \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_INDEX(state), \
		BOOST_PP_INC(BOOST_PP_TUPLE_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_TYPES(state))) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN(d,state) \
	BOOST_PP_WHILE_ ## d \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_PRED, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP, \
		BOOST_PP_TUPLE_PUSH_BACK(BOOST_PP_TUPLE_PUSH_BACK(state,((SEQ,1),(LIST,1),(ARRAY,0),(TUPLE,0))),0) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_ID_LOOP(d,state) \
	BOOST_PP_WHILE_ ## d \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_PRED, \
		BOOST_VMD_DETAIL_SEQUENCE_INNER_OP, \
		BOOST_PP_TUPLE_PUSH_BACK(BOOST_PP_TUPLE_PUSH_BACK(state,((NUMBER,0),(IDENTIFIER,1))),0) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_ID_EL(d,state) \
	( \
	BOOST_VMD_AFTER_LIST_D(d,BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state)), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT_ADD(state,(BOOST_VMD_TYPE_LIST,BOOST_PP_NIL)), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state) \
	) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_ID(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY_LIST \
			( \
			BOOST_VMD_BEGIN_IDENTIFIER \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
				) \
			), \
		BOOST_VMD_DETAIL_SEQUENCE_OP_ID_EL, \
		BOOST_VMD_DETAIL_SEQUENCE_OP_ID_LOOP \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP_REDUCE_STATE(state) \
	( \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_OUTTYPE(state) \
	) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_OP(d,state) \
	BOOST_VMD_DETAIL_SEQUENCE_OP_REDUCE_STATE \
		( \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_IS_BEGIN_TUPLE \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
				), \
			BOOST_VMD_DETAIL_SEQUENCE_OP_PAREN, \
			BOOST_VMD_DETAIL_SEQUENCE_OP_ID \
			) \
		(d,state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PRED_CELEM_SZ(d,state) \
	BOOST_PP_LESS_EQUAL_D \
		( \
		d, \
		BOOST_PP_SEQ_SIZE(BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state)), \
		BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PRED_CELEM(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_PRED_ICELEM(d,state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PRED_ICELEM(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_BITOR \
			( \
			BOOST_VMD_IS_EMPTY \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_ELEM(state) \
				), \
			BOOST_VMD_IS_EMPTY \
				( \
				BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state) \
				) \
			), \
		BOOST_VMD_IDENTITY(1), \
		BOOST_VMD_DETAIL_SEQUENCE_PRED_CELEM_SZ \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_PRED(d,state) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_IPRED(d,state)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_IPRED(d,state) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
			), \
		BOOST_VMD_IDENTITY(0), \
		BOOST_VMD_DETAIL_SEQUENCE_PRED_CELEM \
		) \
	(d,state) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE_CHECK(output) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL(output,BOOST_VMD_TYPE_ARRAY), \
		(0,()), \
		BOOST_PP_NIL \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE(output) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_BITOR \
			( \
			BOOST_PP_EQUAL(output,BOOST_VMD_TYPE_SEQ), \
			BOOST_PP_EQUAL(output,BOOST_VMD_TYPE_TUPLE) \
			), \
		BOOST_VMD_EMPTY, \
		BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE_CHECK \
		) \
	(output) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS(vseq,elem,output) \
	BOOST_PP_TUPLE_ELEM \
		( \
		0, \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE(vseq,elem,output) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D(d,vseq,elem,output) \
	BOOST_PP_TUPLE_ELEM \
		( \
		0, \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_D(d,vseq,elem,output) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET(state) \
	( \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_RESULT(state), \
	BOOST_VMD_DETAIL_SEQUENCE_STATE_INPUT(state) \
	) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE(vseq,elem,output) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET \
		( \
		BOOST_PP_WHILE \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_PRED, \
			BOOST_VMD_DETAIL_SEQUENCE_OP, \
			(vseq,BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE(output),elem,output) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_D(d,vseq,elem,output) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_GET \
		( \
		BOOST_PP_WHILE_ ## d \
			( \
			BOOST_VMD_DETAIL_SEQUENCE_PRED, \
			BOOST_VMD_DETAIL_SEQUENCE_OP, \
			(vseq,BOOST_VMD_DETAIL_SEQUENCE_EMPTY_TYPE(output),elem,output) \
			) \
		) \
/**/

/*--------------------------------------------------------------------------------------------------------------------------*/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ_CHELM(seq,elem) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_GREATER(BOOST_PP_SEQ_SIZE(seq),elem), \
		BOOST_PP_SEQ_ELEM, \
		BOOST_VMD_EMPTY \
		) \
	(elem,seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ(seq,elem) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(seq), \
		BOOST_VMD_EMPTY, \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ_CHELM \
		) \
	(seq,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ_CHELM_EXTRACT(tuple,elem) \
	BOOST_PP_TUPLE_REPLACE \
		( \
		tuple, \
		0, \
		BOOST_PP_SEQ_ELEM(elem,BOOST_PP_TUPLE_ELEM(0,tuple)) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ_CHELM(tuple,elem) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_GREATER(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(0,tuple)),elem), \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ_CHELM_EXTRACT, \
		BOOST_VMD_DETAIL_EMPTY_RESULT \
		) \
	(tuple,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ(tuple,elem) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,tuple)), \
		BOOST_VMD_DETAIL_EMPTY_RESULT, \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ_CHELM \
		) \
	(tuple,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_RP(seq) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(seq), \
		BOOST_VMD_EMPTY, \
		BOOST_PP_SEQ_TO_TUPLE \
		) \
	(seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP_EMPTY(seq) \
	(0,()) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP(seq) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(seq), \
		BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP_EMPTY, \
		BOOST_PP_SEQ_TO_ARRAY \
		) \
	(seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_LIST_OP(s,data,elem) \
	BOOST_PP_TUPLE_ELEM(data,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST_TR(list) \
	BOOST_PP_LIST_TRANSFORM(BOOST_VMD_DETAIL_SEQUENCE_TO_LIST_OP,1,list) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ_OP(s,data,elem) \
	BOOST_PP_TUPLE_ELEM(data,elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR_NE(seq) \
	BOOST_PP_SEQ_TRANSFORM(BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ_OP,1,seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR(seq) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(seq), \
		BOOST_VMD_EMPTY, \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR_NE \
		) \
	(seq) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE_TUPLE(selem) \
	BOOST_PP_TUPLE_ELEM(1,selem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE(selem) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(selem), \
		BOOST_VMD_EMPTY, \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE_TUPLE \
		) \
	(selem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_ICE_REP(tuple) \
	BOOST_PP_TUPLE_REPLACE \
		( \
		tuple, \
		0, \
		BOOST_PP_TUPLE_ELEM(1,BOOST_PP_TUPLE_ELEM(0,tuple)) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_ICE(tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,tuple)), \
		BOOST_VMD_IDENTITY(tuple), \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_ICE_REP \
		) \
	(tuple) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_CE(tuple) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_ICE(tuple)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS(tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_EMPTY(tuple), \
		BOOST_VMD_EMPTY, \
		BOOST_PP_TUPLE_ENUM \
		) \
	(tuple) \
/**/

/*--------------------------------------------------------------------------------------------------------------------------*/

// ELEM

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM(vseq,elem) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ(BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS(vseq,elem,BOOST_VMD_TYPE_SEQ),elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_D(d,vseq,elem) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_FSEQ(BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D(d,vseq,elem,BOOST_VMD_TYPE_SEQ),elem) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM(vseq,elem) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE(BOOST_VMD_DETAIL_SEQUENCE_ELEM(vseq,elem)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_D(d,vseq,elem) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_CE(BOOST_VMD_DETAIL_SEQUENCE_ELEM_D(d,vseq,elem)) \
/**/

// ELEM SPLIT

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT(vseq,elem) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE(vseq,elem,BOOST_VMD_TYPE_SEQ), \
		elem \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_D(d,vseq,elem) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_FSEQ \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_TUPLE_D(d,vseq,elem,BOOST_VMD_TYPE_SEQ), \
		elem \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT(vseq,elem) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_CE \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT(vseq,elem) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_D(d,vseq,elem) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_CE \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_ELEM_SPLIT_D(d,vseq,elem) \
		) \
/**/

// AFTER

#define BOOST_VMD_DETAIL_SEQUENCE_AFTER(vseq,elem) \
	BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT(vseq,elem)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_AFTER_D(d,vseq,elem) \
	BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_DETAIL_SEQUENCE_DATA_ELEM_SPLIT_D(d,vseq,elem)) \
/**/

// SIZE

#define BOOST_VMD_DETAIL_SEQUENCE_SIZE(vseq) \
	BOOST_PP_ARRAY_SIZE(BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY(vseq)) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_SIZE_D(d,vseq) \
	BOOST_PP_ARRAY_SIZE(BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_D(d,vseq)) \
/**/

// ARRAY

#define BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS(vseq,,BOOST_VMD_TYPE_ARRAY) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D(d,vseq,,BOOST_VMD_TYPE_ARRAY) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_ARRAY(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_ARRAY_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_TO_ARRAY_RP \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_D(d,vseq) \
		) \
/**/

// LIST

#define BOOST_VMD_DETAIL_SEQUENCE_TO_LIST(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS(vseq,,BOOST_VMD_TYPE_LIST) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_LIST_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D(d,vseq,,BOOST_VMD_TYPE_LIST)
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST_TR \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_LIST(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_LIST_TR \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_LIST_D(d,vseq) \
		) \
/**/

// SEQ

#define BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS(vseq,,BOOST_VMD_TYPE_SEQ) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D(d,vseq,,BOOST_VMD_TYPE_SEQ) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_TR \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_SEQ_D(d,vseq) \
		) \
/**/

// TUPLE

#define BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS(vseq,,BOOST_VMD_TYPE_TUPLE) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ELEM_PROCESS_D(d,vseq,,BOOST_VMD_TYPE_TUPLE) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_TUPLE(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_RP \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_TUPLE_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_RP \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_SEQ_D(d,vseq) \
		) \
/**/

// ENUM

#define BOOST_VMD_DETAIL_SEQUENCE_ENUM(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_ENUM_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_TO_TUPLE_D(d,vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ENUM(vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_TUPLE(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_SEQUENCE_DATA_ENUM_D(d,vseq) \
	BOOST_VMD_DETAIL_SEQUENCE_ENUM_PROCESS \
		( \
		BOOST_VMD_DETAIL_SEQUENCE_DATA_TO_TUPLE_D(d,vseq) \
		) \
/**/

#endif /* BOOST_VMD_DETAIL_SEQUENCE_HPP */
