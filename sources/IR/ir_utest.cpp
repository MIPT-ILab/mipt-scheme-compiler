/**
 * @file ir/ir_utest.cpp
 * Unit testing of IR
 */
#include <boost/test/unit_test.hpp>
#include "ir_iface.hpp"

namespace ir
{

BOOST_AUTO_TEST_SUITE( IR)

BOOST_AUTO_TEST_CASE( ir_basic)
{
    cout << "------------------------------------------------";
    cout << "\nTests with operations:\n";
    /** Constructor of Object */
    Object t1;
    BOOST_CHECK_EQUAL( t1.id(), -1);
    BOOST_CHECK_EQUAL( t1.type(), OBJ_NAMES_NUM);
    BOOST_CHECK_EQUAL( t1.isVirtual(), true);
    /** Set Object t1 */
    t1.setId( 1);
    BOOST_CHECK_EQUAL( t1.id(), 1);
    t1.setType( OBJ_NAME_REG);
    BOOST_CHECK_EQUAL( t1.type(), OBJ_NAME_REG);
    /** Constructor of Operation */
    Operation op1( 1);
    /** Print empty operation */
    //cout << "Empty Operation" << endl;
    //cout << op1 << endl;
    BOOST_CHECK_EQUAL( op1.id(), 1);
    BOOST_CHECK_EQUAL( op1.name(), OPERS_NUM);
    /** Set Operation (MOV) */
    op1.setName( OPER_MOV);
    BOOST_CHECK_EQUAL( op1.name(), OPER_MOV);
    op1.setArgType( 0, OP_TYPE_IMM);
    op1.setArgImm( 0, 10);
    BOOST_CHECK_EQUAL( op1.arg( 0).constValue(), 10);
    op1.setResType( 0, OP_TYPE_OBJ);
    op1.setResObj( 0, t1);
    /** Print Operation (MOV) */
    cout << "Operation MOV:" << endl;
    cout << op1 << endl;
    /**Set Operation (ADD) */
    Operation op2( 2);
    op2.setName( OPER_ADD);
    BOOST_CHECK_EQUAL( op2.name(), OPER_ADD);
    cout << "Without arguments and results" << endl;
    cout << op2 << endl;
    op2.setArgType( 0, OP_TYPE_OBJ);
    op2.setArgObj( 0, t1);
    BOOST_CHECK_EQUAL( op2.arg( 0).object(), &t1);
    op2.setArgType( 1, OP_TYPE_IMM);
    op2.setArgImm( 1, 20);
    BOOST_CHECK_EQUAL( op2.arg( 1).constValue(), 20);
    Object t2;
    t2.setId( 2);
    t2.setVirtual( 0);
    BOOST_CHECK_EQUAL( t2.isVirtual(), false);
    t2.setType( OBJ_NAME_REG);
    op2.setResType( 0, OP_TYPE_OBJ);
    op2.setResObj( 0, t2);
    cout << "Operation ADD" << endl;
    cout << op2 << endl;
    cout << "------------------------------------------------";
    cout << endl;
    /** Constructor of Object */
    cout << "Tests with basic blocks:" << endl;
    BasicBlock bb1( 1);
    BOOST_CHECK_EQUAL( bb1.id(), 1);
    cout << "Empty Basic Block" << endl;
    cout << bb1 << endl;
    bb1.addOperation( op1);
    bb1.addOperation( op2);
    cout << "1 Basic Block" << endl;
    cout << bb1 << endl;
    cout << "1 Basic Block with next and prev" << endl;
    BasicBlock bb2 (2);
    BasicBlock bb3( 3);
    bb1.setPrevBlock( bb2);
    bb1.setNextBlock( bb3);
    cout << bb1 << endl;
    cout << "------------------------------------------------";
    cout << endl;
}



BOOST_AUTO_TEST_SUITE_END()

}
