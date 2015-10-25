/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2015 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_INTERFACE_STATEMENT_H_
#define incl_HPHP_INTERFACE_STATEMENT_H_

#include "hphp/compiler/statement/statement.h"
#include <vector>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

DECLARE_BOOST_TYPES(StatementList);
DECLARE_BOOST_TYPES(ExpressionList);
DECLARE_BOOST_TYPES(ClassScope);
DECLARE_BOOST_TYPES(InterfaceStatement);

struct InterfaceStatement : public Statement, public IParseHandler {
protected:
  InterfaceStatement(STATEMENT_CONSTRUCTOR_BASE_PARAMETERS,
                     const std::string &name, ExpressionListPtr base,
                     const std::string &docComment, StatementListPtr stmt,
                     ExpressionListPtr attrList);
public:
  InterfaceStatement(STATEMENT_CONSTRUCTOR_PARAMETERS,
                     const std::string &name, ExpressionListPtr base,
                     const std::string &docComment, StatementListPtr stmt,
                     ExpressionListPtr attrList);

  DECLARE_STATEMENT_VIRTUAL_FUNCTIONS;
  StatementPtr preOptimize(AnalysisResultConstPtr ar) override;
  bool hasDecl() const override { return true; }
  bool hasImpl() const override;
  int getRecursiveCount() const override;
  // implementing IParseHandler
  void onParse(AnalysisResultConstPtr ar, FileScopePtr scope) override;

  int getLocalEffects() const override;

  std::string getName() const override;
  const std::string &getOriginalName() const { return m_originalName; }
  ClassScopeRawPtr getClassScope() const {
    BlockScopeRawPtr b = getScope();
    assert(b->is(BlockScope::ClassScope));
    return ClassScopeRawPtr((ClassScope*)b.get());
  }

  StatementListPtr getStmts() { return m_stmt; }
  void checkArgumentsToPromote(FileScopeRawPtr scope,
                               ExpressionListPtr params, int type);
protected:
  std::string m_originalName;
  ExpressionListPtr m_base;
  std::string m_docComment;
  StatementListPtr m_stmt;
  ExpressionListPtr m_attrList;
  void checkVolatile(AnalysisResultConstPtr ar);
private:
  bool checkVolatileBases(AnalysisResultConstPtr ar);
};

///////////////////////////////////////////////////////////////////////////////
}
#endif // incl_HPHP_INTERFACE_STATEMENT_H_
