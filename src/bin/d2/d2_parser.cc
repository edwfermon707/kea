// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   d2_parser_lex



#include "d2_parser.h"


// Unqualified %code blocks.
#line 34 "d2_parser.yy"

#include <d2/parser_context.h>

#line 52 "d2_parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if D2_PARSER_DEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !D2_PARSER_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !D2_PARSER_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "d2_parser.yy"
namespace isc { namespace d2 {
#line 145 "d2_parser.cc"

  /// Build a parser object.
  D2Parser::D2Parser (isc::d2::D2ParserContext& ctx_yyarg)
#if D2_PARSER_DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      ctx (ctx_yyarg)
  {}

  D2Parser::~D2Parser ()
  {}

  D2Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  D2Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  D2Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  D2Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  D2Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  D2Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  D2Parser::symbol_kind_type
  D2Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  D2Parser::stack_symbol_type::stack_symbol_type ()
  {}

  D2Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.YY_MOVE_OR_COPY< ElementPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  D2Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.move< ElementPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  D2Parser::stack_symbol_type&
  D2Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.copy< ElementPtr > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  D2Parser::stack_symbol_type&
  D2Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.move< ElementPtr > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  D2Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if D2_PARSER_DEBUG
  template <typename Base>
  void
  D2Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_STRING: // "constant string"
#line 117 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 384 "d2_parser.cc"
        break;

      case symbol_kind::S_INTEGER: // "integer"
#line 117 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < int64_t > (); }
#line 390 "d2_parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "floating point"
#line 117 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < double > (); }
#line 396 "d2_parser.cc"
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
#line 117 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < bool > (); }
#line 402 "d2_parser.cc"
        break;

      case symbol_kind::S_value: // value
#line 117 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 408 "d2_parser.cc"
        break;

      case symbol_kind::S_map_value: // map_value
#line 117 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 414 "d2_parser.cc"
        break;

      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
#line 117 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 420 "d2_parser.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  D2Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  D2Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  D2Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if D2_PARSER_DEBUG
  std::ostream&
  D2Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  D2Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  D2Parser::debug_level_type
  D2Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  D2Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // D2_PARSER_DEBUG

  D2Parser::state_type
  D2Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  D2Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  D2Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  D2Parser::operator() ()
  {
    return parse ();
  }

  int
  D2Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        yylhs.value.emplace< ElementPtr > ();
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INTEGER: // "integer"
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_STRING: // "constant string"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // $@1: %empty
#line 126 "d2_parser.yy"
                     { ctx.ctx_ = ctx.NO_KEYWORD; }
#line 695 "d2_parser.cc"
    break;

  case 4: // $@2: %empty
#line 127 "d2_parser.yy"
                         { ctx.ctx_ = ctx.CONFIG; }
#line 701 "d2_parser.cc"
    break;

  case 6: // $@3: %empty
#line 128 "d2_parser.yy"
                    { ctx.ctx_ = ctx.DHCPDDNS; }
#line 707 "d2_parser.cc"
    break;

  case 8: // $@4: %empty
#line 129 "d2_parser.yy"
                    { ctx.ctx_ = ctx.TSIG_KEY; }
#line 713 "d2_parser.cc"
    break;

  case 10: // $@5: %empty
#line 130 "d2_parser.yy"
                     { ctx.ctx_ = ctx.TSIG_KEYS; }
#line 719 "d2_parser.cc"
    break;

  case 12: // $@6: %empty
#line 131 "d2_parser.yy"
                       { ctx.ctx_ = ctx.DDNS_DOMAIN; }
#line 725 "d2_parser.cc"
    break;

  case 14: // $@7: %empty
#line 132 "d2_parser.yy"
                        { ctx.ctx_ = ctx.DDNS_DOMAINS; }
#line 731 "d2_parser.cc"
    break;

  case 16: // $@8: %empty
#line 133 "d2_parser.yy"
                      { ctx.ctx_ = ctx.DNS_SERVERS; }
#line 737 "d2_parser.cc"
    break;

  case 18: // $@9: %empty
#line 134 "d2_parser.yy"
                       { ctx.ctx_ = ctx.DNS_SERVERS; }
#line 743 "d2_parser.cc"
    break;

  case 20: // $@10: %empty
#line 135 "d2_parser.yy"
                         { ctx.ctx_ = ctx.HOOKS_LIBRARIES; }
#line 749 "d2_parser.cc"
    break;

  case 22: // value: "integer"
#line 143 "d2_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location))); }
#line 755 "d2_parser.cc"
    break;

  case 23: // value: "floating point"
#line 144 "d2_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location))); }
#line 761 "d2_parser.cc"
    break;

  case 24: // value: "boolean"
#line 145 "d2_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location))); }
#line 767 "d2_parser.cc"
    break;

  case 25: // value: "constant string"
#line 146 "d2_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location))); }
#line 773 "d2_parser.cc"
    break;

  case 26: // value: "null"
#line 147 "d2_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new NullElement(ctx.loc2pos(yystack_[0].location))); }
#line 779 "d2_parser.cc"
    break;

  case 27: // value: map2
#line 148 "d2_parser.yy"
            { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 785 "d2_parser.cc"
    break;

  case 28: // value: list_generic
#line 149 "d2_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 791 "d2_parser.cc"
    break;

  case 29: // sub_json: value
#line 152 "d2_parser.yy"
                {
    // Push back the JSON value on the stack
    ctx.stack_.push_back(yystack_[0].value.as < ElementPtr > ());
}
#line 800 "d2_parser.cc"
    break;

  case 30: // $@11: %empty
#line 157 "d2_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 811 "d2_parser.cc"
    break;

  case 31: // map2: "{" $@11 map_content "}"
#line 162 "d2_parser.yy"
                             {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 821 "d2_parser.cc"
    break;

  case 32: // map_value: map2
#line 168 "d2_parser.yy"
                { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 827 "d2_parser.cc"
    break;

  case 35: // not_empty_map: "constant string" ":" value
#line 175 "d2_parser.yy"
                                  {
                  // map containing a single entry
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 837 "d2_parser.cc"
    break;

  case 36: // not_empty_map: not_empty_map "," "constant string" ":" value
#line 180 "d2_parser.yy"
                                                      {
                  // map consisting of a shorter map followed by
                  // comma and string:value
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 848 "d2_parser.cc"
    break;

  case 37: // $@12: %empty
#line 188 "d2_parser.yy"
                              {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 857 "d2_parser.cc"
    break;

  case 38: // list_generic: "[" $@12 list_content "]"
#line 191 "d2_parser.yy"
                               {
    // list parsing complete. Put any sanity checking here
}
#line 865 "d2_parser.cc"
    break;

  case 41: // not_empty_list: value
#line 199 "d2_parser.yy"
                      {
                  // List consisting of a single element.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 874 "d2_parser.cc"
    break;

  case 42: // not_empty_list: not_empty_list "," value
#line 203 "d2_parser.yy"
                                           {
                  // List ending with , and a value.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 883 "d2_parser.cc"
    break;

  case 43: // unknown_map_entry: "constant string" ":"
#line 214 "d2_parser.yy"
                                {
    const std::string& where = ctx.contextName();
    const std::string& keyword = yystack_[1].value.as < std::string > ();
    error(yystack_[1].location,
          "got unexpected keyword \"" + keyword + "\" in " + where + " map.");
}
#line 894 "d2_parser.cc"
    break;

  case 44: // $@13: %empty
#line 223 "d2_parser.yy"
                           {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 905 "d2_parser.cc"
    break;

  case 45: // syntax_map: "{" $@13 global_object "}"
#line 228 "d2_parser.yy"
                               {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 915 "d2_parser.cc"
    break;

  case 46: // $@14: %empty
#line 236 "d2_parser.yy"
                        {
    ctx.unique("DhcpDdns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("DhcpDdns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCPDDNS);
}
#line 927 "d2_parser.cc"
    break;

  case 47: // global_object: "DhcpDdns" $@14 ":" "{" dhcpddns_params "}"
#line 242 "d2_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 936 "d2_parser.cc"
    break;

  case 48: // $@15: %empty
#line 247 "d2_parser.yy"
                             {
    // Parse the dhcpddns map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 946 "d2_parser.cc"
    break;

  case 49: // sub_dhcpddns: "{" $@15 dhcpddns_params "}"
#line 251 "d2_parser.yy"
                                 {
    // parsing completed
}
#line 954 "d2_parser.cc"
    break;

  case 67: // $@16: %empty
#line 277 "d2_parser.yy"
                       {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 963 "d2_parser.cc"
    break;

  case 68: // ip_address: "ip-address" $@16 ":" "constant string"
#line 280 "d2_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", s);
    ctx.leave();
}
#line 973 "d2_parser.cc"
    break;

  case 69: // port: "port" ":" "integer"
#line 286 "d2_parser.yy"
                         {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () <= 0 || yystack_[0].value.as < int64_t > () >= 65536 ) {
        error(yystack_[0].location, "port must be greater than zero but less than 65536");
    }
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", i);
}
#line 986 "d2_parser.cc"
    break;

  case 70: // dns_server_timeout: "dns-server-timeout" ":" "integer"
#line 295 "d2_parser.yy"
                                                     {
    ctx.unique("dns-server-timeout", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () <= 0) {
        error(yystack_[0].location, "dns-server-timeout must be greater than zero");
    } else {
        ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("dns-server-timeout", i);
    }
}
#line 1000 "d2_parser.cc"
    break;

  case 71: // dns_server_max_attempts: "dns_server_max-attempts" ":" "integer"
#line 305 "d2_parser.yy"
                                                               {
    ctx.unique("dns-server-max-attempts", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () <= 0) {
        error(yystack_[0].location, "dns-server-max-attempts must be greater than zero");
    } else {
        ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("dns-server-max-attempts", i);
    }
}
#line 1014 "d2_parser.cc"
    break;

  case 72: // $@17: %empty
#line 315 "d2_parser.yy"
                           {
    ctx.unique("ncr-protocol", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_PROTOCOL);
}
#line 1023 "d2_parser.cc"
    break;

  case 73: // ncr_protocol: "ncr-protocol" $@17 ":" ncr_protocol_value
#line 318 "d2_parser.yy"
                           {
    ctx.stack_.back()->set("ncr-protocol", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1032 "d2_parser.cc"
    break;

  case 74: // ncr_protocol_value: "UDP"
#line 324 "d2_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("UDP", ctx.loc2pos(yystack_[0].location))); }
#line 1038 "d2_parser.cc"
    break;

  case 75: // ncr_protocol_value: "TCP"
#line 325 "d2_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("TCP", ctx.loc2pos(yystack_[0].location))); }
#line 1044 "d2_parser.cc"
    break;

  case 76: // $@18: %empty
#line 328 "d2_parser.yy"
                       {
    ctx.unique("ncr-format", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_FORMAT);
}
#line 1053 "d2_parser.cc"
    break;

  case 77: // ncr_format: "ncr-format" $@18 ":" "JSON"
#line 331 "d2_parser.yy"
             {
    ElementPtr json(new StringElement("JSON", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ncr-format", json);
    ctx.leave();
}
#line 1063 "d2_parser.cc"
    break;

  case 78: // $@19: %empty
#line 337 "d2_parser.yy"
                           {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1071 "d2_parser.cc"
    break;

  case 79: // user_context: "user-context" $@19 ":" map_value
#line 339 "d2_parser.yy"
                  {
    ElementPtr parent = ctx.stack_.back();
    ElementPtr user_context = yystack_[0].value.as < ElementPtr > ();
    ConstElementPtr old = parent->get("user-context");

    // Handle already existing user context
    if (old) {
        // Check if it was a comment or a duplicate
        if ((old->size() != 1) || !old->contains("comment")) {
            std::stringstream msg;
            msg << "duplicate user-context entries (previous at "
                << old->getPosition().str() << ")";
            error(yystack_[3].location, msg.str());
        }
        // Merge the comment
        user_context->set("comment", old->get("comment"));
    }

    // Set the user context
    parent->set("user-context", user_context);
    ctx.leave();
}
#line 1098 "d2_parser.cc"
    break;

  case 80: // $@20: %empty
#line 362 "d2_parser.yy"
                 {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1106 "d2_parser.cc"
    break;

  case 81: // comment: "comment" $@20 ":" "constant string"
#line 364 "d2_parser.yy"
               {
    ElementPtr parent = ctx.stack_.back();
    ElementPtr user_context(new MapElement(ctx.loc2pos(yystack_[3].location)));
    ElementPtr comment(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    user_context->set("comment", comment);

    // Handle already existing user context
    ConstElementPtr old = parent->get("user-context");
    if (old) {
        // Check for duplicate comment
        if (old->contains("comment")) {
            std::stringstream msg;
            msg << "duplicate user-context/comment entries (previous at "
                << old->getPosition().str() << ")";
            error(yystack_[3].location, msg.str());
        }
        // Merge the user context in the comment
        merge(user_context, old);
    }

    // Set the user context
    parent->set("user-context", user_context);
    ctx.leave();
}
#line 1135 "d2_parser.cc"
    break;

  case 82: // $@21: %empty
#line 389 "d2_parser.yy"
                            {
    ctx.unique("forward-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("forward-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.FORWARD_DDNS);
}
#line 1147 "d2_parser.cc"
    break;

  case 83: // forward_ddns: "forward-ddns" $@21 ":" "{" ddns_mgr_params "}"
#line 395 "d2_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1156 "d2_parser.cc"
    break;

  case 84: // $@22: %empty
#line 400 "d2_parser.yy"
                            {
    ctx.unique("reverse-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reverse-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.REVERSE_DDNS);
}
#line 1168 "d2_parser.cc"
    break;

  case 85: // reverse_ddns: "reverse-ddns" $@22 ":" "{" ddns_mgr_params "}"
#line 406 "d2_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1177 "d2_parser.cc"
    break;

  case 92: // $@23: %empty
#line 425 "d2_parser.yy"
                           {
    ctx.unique("ddns-domains", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-domains", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.DDNS_DOMAINS);
}
#line 1189 "d2_parser.cc"
    break;

  case 93: // ddns_domains: "ddns-domains" $@23 ":" "[" ddns_domain_list "]"
#line 431 "d2_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1198 "d2_parser.cc"
    break;

  case 94: // $@24: %empty
#line 436 "d2_parser.yy"
                                  {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 1207 "d2_parser.cc"
    break;

  case 95: // sub_ddns_domains: "[" $@24 ddns_domain_list "]"
#line 439 "d2_parser.yy"
                                   {
    // parsing completed
}
#line 1215 "d2_parser.cc"
    break;

  case 100: // $@25: %empty
#line 451 "d2_parser.yy"
                            {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1225 "d2_parser.cc"
    break;

  case 101: // ddns_domain: "{" $@25 ddns_domain_params "}"
#line 455 "d2_parser.yy"
                                    {
    ctx.stack_.pop_back();
}
#line 1233 "d2_parser.cc"
    break;

  case 102: // $@26: %empty
#line 459 "d2_parser.yy"
                                {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1242 "d2_parser.cc"
    break;

  case 103: // sub_ddns_domain: "{" $@26 ddns_domain_params "}"
#line 462 "d2_parser.yy"
                                    {
    // parsing completed
}
#line 1250 "d2_parser.cc"
    break;

  case 112: // $@27: %empty
#line 479 "d2_parser.yy"
                       {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1259 "d2_parser.cc"
    break;

  case 113: // ddns_domain_name: "name" $@27 ":" "constant string"
#line 482 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () == "") {
        error(yystack_[1].location, "Ddns domain name cannot be blank");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 1273 "d2_parser.cc"
    break;

  case 114: // $@28: %empty
#line 492 "d2_parser.yy"
                        {
    ctx.unique("key-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1282 "d2_parser.cc"
    break;

  case 115: // ddns_key_name: "key-name" $@28 ":" "constant string"
#line 495 "d2_parser.yy"
               {
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("key-name", name);
    ctx.leave();
}
#line 1293 "d2_parser.cc"
    break;

  case 116: // $@29: %empty
#line 505 "d2_parser.yy"
                         {
    ctx.unique("dns-servers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dns-servers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.DNS_SERVERS);
}
#line 1305 "d2_parser.cc"
    break;

  case 117: // dns_servers: "dns-servers" $@29 ":" "[" dns_server_list "]"
#line 511 "d2_parser.yy"
                                                        {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1314 "d2_parser.cc"
    break;

  case 118: // $@30: %empty
#line 516 "d2_parser.yy"
                                 {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 1323 "d2_parser.cc"
    break;

  case 119: // sub_dns_servers: "[" $@30 dns_server_list "]"
#line 519 "d2_parser.yy"
                                  {
    // parsing completed
}
#line 1331 "d2_parser.cc"
    break;

  case 122: // $@31: %empty
#line 527 "d2_parser.yy"
                           {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1341 "d2_parser.cc"
    break;

  case 123: // dns_server: "{" $@31 dns_server_params "}"
#line 531 "d2_parser.yy"
                                   {
    ctx.stack_.pop_back();
}
#line 1349 "d2_parser.cc"
    break;

  case 124: // $@32: %empty
#line 535 "d2_parser.yy"
                               {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1358 "d2_parser.cc"
    break;

  case 125: // sub_dns_server: "{" $@32 dns_server_params "}"
#line 538 "d2_parser.yy"
                                   {
    // parsing completed
}
#line 1366 "d2_parser.cc"
    break;

  case 135: // $@33: %empty
#line 555 "d2_parser.yy"
                              {
    ctx.unique("hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1375 "d2_parser.cc"
    break;

  case 136: // dns_server_hostname: "hostname" $@33 ":" "constant string"
#line 558 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () != "") {
        error(yystack_[1].location, "hostname is not yet supported");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname", name);
    ctx.leave();
}
#line 1389 "d2_parser.cc"
    break;

  case 137: // $@34: %empty
#line 568 "d2_parser.yy"
                                  {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1398 "d2_parser.cc"
    break;

  case 138: // dns_server_ip_address: "ip-address" $@34 ":" "constant string"
#line 571 "d2_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", s);
    ctx.leave();
}
#line 1408 "d2_parser.cc"
    break;

  case 139: // dns_server_port: "port" ":" "integer"
#line 577 "d2_parser.yy"
                                    {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () <= 0 || yystack_[0].value.as < int64_t > () >= 65536 ) {
        error(yystack_[0].location, "port must be greater than zero but less than 65536");
    }
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", i);
}
#line 1421 "d2_parser.cc"
    break;

  case 140: // $@35: %empty
#line 592 "d2_parser.yy"
                     {
    ctx.unique("tsig-keys", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("tsig-keys", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.TSIG_KEYS);
}
#line 1433 "d2_parser.cc"
    break;

  case 141: // tsig_keys: "tsig-keys" $@35 ":" "[" tsig_keys_list "]"
#line 598 "d2_parser.yy"
                                                       {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1442 "d2_parser.cc"
    break;

  case 142: // $@36: %empty
#line 603 "d2_parser.yy"
                               {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 1451 "d2_parser.cc"
    break;

  case 143: // sub_tsig_keys: "[" $@36 tsig_keys_list "]"
#line 606 "d2_parser.yy"
                                 {
    // parsing completed
}
#line 1459 "d2_parser.cc"
    break;

  case 148: // $@37: %empty
#line 618 "d2_parser.yy"
                         {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1469 "d2_parser.cc"
    break;

  case 149: // tsig_key: "{" $@37 tsig_key_params "}"
#line 622 "d2_parser.yy"
                                 {
    ctx.stack_.pop_back();
}
#line 1477 "d2_parser.cc"
    break;

  case 150: // $@38: %empty
#line 626 "d2_parser.yy"
                             {
    // Parse tsig key list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1487 "d2_parser.cc"
    break;

  case 151: // sub_tsig_key: "{" $@38 tsig_key_params "}"
#line 630 "d2_parser.yy"
                                 {
    // parsing completed
}
#line 1495 "d2_parser.cc"
    break;

  case 161: // $@39: %empty
#line 648 "d2_parser.yy"
                    {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1504 "d2_parser.cc"
    break;

  case 162: // tsig_key_name: "name" $@39 ":" "constant string"
#line 651 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () == "") {
        error(yystack_[1].location, "TSIG key name cannot be blank");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 1518 "d2_parser.cc"
    break;

  case 163: // $@40: %empty
#line 661 "d2_parser.yy"
                              {
    ctx.unique("algorithm", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1527 "d2_parser.cc"
    break;

  case 164: // tsig_key_algorithm: "algorithm" $@40 ":" "constant string"
#line 664 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () == "") {
        error(yystack_[1].location, "TSIG key algorithm cannot be blank");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("algorithm", elem);
    ctx.leave();
}
#line 1540 "d2_parser.cc"
    break;

  case 165: // tsig_key_digest_bits: "digest-bits" ":" "integer"
#line 673 "d2_parser.yy"
                                                {
    ctx.unique("digest-bits", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () < 0 || (yystack_[0].value.as < int64_t > () > 0  && (yystack_[0].value.as < int64_t > () % 8 != 0))) {
        error(yystack_[0].location, "TSIG key digest-bits must either be zero or a positive, multiple of eight");
    }
    ElementPtr elem(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("digest-bits", elem);
}
#line 1553 "d2_parser.cc"
    break;

  case 166: // $@41: %empty
#line 682 "d2_parser.yy"
                        {
    ctx.unique("secret", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1562 "d2_parser.cc"
    break;

  case 167: // tsig_key_secret: "secret" $@41 ":" "constant string"
#line 685 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () == "") {
        error(yystack_[1].location, "TSIG key secret cannot be blank");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("secret", elem);
    ctx.leave();
}
#line 1575 "d2_parser.cc"
    break;

  case 168: // $@42: %empty
#line 699 "d2_parser.yy"
                               {
    ctx.unique("control-socket", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("control-socket", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.CONTROL_SOCKET);
}
#line 1587 "d2_parser.cc"
    break;

  case 169: // control_socket: "control-socket" $@42 ":" "{" control_socket_params "}"
#line 705 "d2_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1596 "d2_parser.cc"
    break;

  case 177: // $@43: %empty
#line 721 "d2_parser.yy"
                                 {
    ctx.unique("socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1605 "d2_parser.cc"
    break;

  case 178: // control_socket_type: "socket-type" $@43 ":" "constant string"
#line 724 "d2_parser.yy"
               {
    ElementPtr stype(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-type", stype);
    ctx.leave();
}
#line 1615 "d2_parser.cc"
    break;

  case 179: // $@44: %empty
#line 730 "d2_parser.yy"
                                 {
    ctx.unique("socket-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1624 "d2_parser.cc"
    break;

  case 180: // control_socket_name: "socket-name" $@44 ":" "constant string"
#line 733 "d2_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-name", name);
    ctx.leave();
}
#line 1634 "d2_parser.cc"
    break;

  case 181: // $@45: %empty
#line 741 "d2_parser.yy"
                                 {
    ctx.unique("hooks-libraries", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hooks-libraries", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOOKS_LIBRARIES);
}
#line 1646 "d2_parser.cc"
    break;

  case 182: // hooks_libraries: "hooks-libraries" $@45 ":" "[" hooks_libraries_list "]"
#line 747 "d2_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1655 "d2_parser.cc"
    break;

  case 187: // $@46: %empty
#line 760 "d2_parser.yy"
                              {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1665 "d2_parser.cc"
    break;

  case 188: // hooks_library: "{" $@46 hooks_params "}"
#line 764 "d2_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 1675 "d2_parser.cc"
    break;

  case 189: // $@47: %empty
#line 770 "d2_parser.yy"
                                  {
    // Parse the hooks-libraries list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1685 "d2_parser.cc"
    break;

  case 190: // sub_hooks_library: "{" $@47 hooks_params "}"
#line 774 "d2_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 1695 "d2_parser.cc"
    break;

  case 196: // $@48: %empty
#line 789 "d2_parser.yy"
                 {
    ctx.unique("library", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1704 "d2_parser.cc"
    break;

  case 197: // library: "library" $@48 ":" "constant string"
#line 792 "d2_parser.yy"
               {
    ElementPtr lib(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("library", lib);
    ctx.leave();
}
#line 1714 "d2_parser.cc"
    break;

  case 198: // $@49: %empty
#line 798 "d2_parser.yy"
                       {
    ctx.unique("parameters", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1723 "d2_parser.cc"
    break;

  case 199: // parameters: "parameters" $@49 ":" map_value
#line 801 "d2_parser.yy"
                  {
    ctx.stack_.back()->set("parameters", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1732 "d2_parser.cc"
    break;

  case 200: // $@50: %empty
#line 808 "d2_parser.yy"
                 {
    ctx.unique("loggers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("loggers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.LOGGERS);
}
#line 1744 "d2_parser.cc"
    break;

  case 201: // loggers: "loggers" $@50 ":" "[" loggers_entries "]"
#line 814 "d2_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1753 "d2_parser.cc"
    break;

  case 204: // $@51: %empty
#line 826 "d2_parser.yy"
                             {
    ElementPtr l(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(l);
    ctx.stack_.push_back(l);
}
#line 1763 "d2_parser.cc"
    break;

  case 205: // logger_entry: "{" $@51 logger_params "}"
#line 830 "d2_parser.yy"
                               {
    ctx.stack_.pop_back();
}
#line 1771 "d2_parser.cc"
    break;

  case 215: // $@52: %empty
#line 847 "d2_parser.yy"
           {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1780 "d2_parser.cc"
    break;

  case 216: // name: "name" $@52 ":" "constant string"
#line 850 "d2_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 1790 "d2_parser.cc"
    break;

  case 217: // debuglevel: "debuglevel" ":" "integer"
#line 856 "d2_parser.yy"
                                     {
    ctx.unique("debuglevel", ctx.loc2pos(yystack_[2].location));
    ElementPtr dl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("debuglevel", dl);
}
#line 1800 "d2_parser.cc"
    break;

  case 218: // $@53: %empty
#line 862 "d2_parser.yy"
                   {
    ctx.unique("severity", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1809 "d2_parser.cc"
    break;

  case 219: // severity: "severity" $@53 ":" "constant string"
#line 865 "d2_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("severity", sev);
    ctx.leave();
}
#line 1819 "d2_parser.cc"
    break;

  case 220: // $@54: %empty
#line 871 "d2_parser.yy"
                                    {
    ctx.unique("output_options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output_options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OUTPUT_OPTIONS);
}
#line 1831 "d2_parser.cc"
    break;

  case 221: // output_options_list: "output_options" $@54 ":" "[" output_options_list_content "]"
#line 877 "d2_parser.yy"
                                                                    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1840 "d2_parser.cc"
    break;

  case 224: // $@55: %empty
#line 886 "d2_parser.yy"
                             {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1850 "d2_parser.cc"
    break;

  case 225: // output_entry: "{" $@55 output_params_list "}"
#line 890 "d2_parser.yy"
                                    {
    ctx.stack_.pop_back();
}
#line 1858 "d2_parser.cc"
    break;

  case 233: // $@56: %empty
#line 905 "d2_parser.yy"
               {
    ctx.unique("output", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1867 "d2_parser.cc"
    break;

  case 234: // output: "output" $@56 ":" "constant string"
#line 908 "d2_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output", sev);
    ctx.leave();
}
#line 1877 "d2_parser.cc"
    break;

  case 235: // flush: "flush" ":" "boolean"
#line 914 "d2_parser.yy"
                           {
    ctx.unique("flush", ctx.loc2pos(yystack_[2].location));
    ElementPtr flush(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush", flush);
}
#line 1887 "d2_parser.cc"
    break;

  case 236: // maxsize: "maxsize" ":" "integer"
#line 920 "d2_parser.yy"
                               {
    ctx.unique("maxsize", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxsize(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxsize", maxsize);
}
#line 1897 "d2_parser.cc"
    break;

  case 237: // maxver: "maxver" ":" "integer"
#line 926 "d2_parser.yy"
                             {
    ctx.unique("maxver", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxver(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxver", maxver);
}
#line 1907 "d2_parser.cc"
    break;

  case 238: // $@57: %empty
#line 932 "d2_parser.yy"
                 {
    ctx.unique("pattern", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1916 "d2_parser.cc"
    break;

  case 239: // pattern: "pattern" $@57 ":" "constant string"
#line 935 "d2_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pattern", sev);
    ctx.leave();
}
#line 1926 "d2_parser.cc"
    break;


#line 1930 "d2_parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  D2Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  D2Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  D2Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // D2Parser::context.
  D2Parser::context::context (const D2Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  D2Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  D2Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  D2Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short D2Parser::yypact_ninf_ = -198;

  const signed char D2Parser::yytable_ninf_ = -1;

  const short
  D2Parser::yypact_[] =
  {
      55,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,    10,     8,     1,    17,    25,    29,    33,    39,    51,
      70,    72,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,     8,    27,    73,     7,    41,    84,    61,   106,
      26,   107,    20,  -198,   118,   122,   131,   126,   139,  -198,
     136,  -198,   170,   172,   173,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,   174,  -198,    23,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,   175,  -198,  -198,  -198,  -198,  -198,
      40,  -198,  -198,  -198,  -198,  -198,  -198,   148,   177,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,    56,  -198,  -198,  -198,
    -198,  -198,   167,   178,  -198,  -198,   179,  -198,  -198,  -198,
    -198,  -198,   112,  -198,  -198,  -198,  -198,  -198,    30,  -198,
    -198,  -198,  -198,   113,  -198,  -198,  -198,  -198,     8,     8,
    -198,   124,   180,  -198,   181,   127,   128,   129,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,  -198,     7,
    -198,   195,   141,   197,   198,    41,  -198,    41,  -198,    84,
     199,   200,   203,    61,  -198,    61,  -198,   106,   207,   154,
     208,    26,  -198,    26,   107,  -198,   210,   211,    13,  -198,
    -198,  -198,   212,   214,   164,  -198,  -198,  -198,    81,   204,
     217,   168,   218,   220,   213,   221,   224,   225,  -198,   176,
    -198,   182,   183,  -198,   119,  -198,   184,   226,   196,  -198,
     120,  -198,   205,  -198,   209,  -198,   150,  -198,   215,   217,
    -198,     8,     7,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,   -17,   -17,    84,    68,   228,   229,  -198,  -198,  -198,
    -198,  -198,   107,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,   152,  -198,  -198,   153,  -198,  -198,  -198,   159,   227,
    -198,  -198,  -198,  -198,  -198,   160,  -198,  -198,  -198,  -198,
     231,   216,  -198,  -198,    57,  -198,   130,  -198,   234,   -17,
    -198,  -198,  -198,   235,   239,    68,  -198,    20,  -198,   228,
      34,   229,  -198,  -198,   240,  -198,   219,   222,  -198,   161,
    -198,  -198,  -198,   242,  -198,  -198,  -198,  -198,   162,  -198,
    -198,  -198,  -198,  -198,  -198,   106,  -198,  -198,  -198,   243,
     244,   158,   245,    34,  -198,   238,   223,   246,  -198,   230,
    -198,  -198,  -198,   248,  -198,  -198,   169,  -198,    49,   248,
    -198,  -198,   252,   253,   254,  -198,   163,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,   258,   171,   232,   233,   262,    49,
    -198,   236,  -198,  -198,  -198,   237,  -198,  -198,  -198
  };

  const unsigned char
  D2Parser::yydefact_[] =
  {
       0,     2,     4,     6,     8,    10,    12,    14,    16,    18,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    37,    30,    26,    25,    22,    23,    24,
      29,     3,    27,    28,    44,     5,    48,     7,   150,     9,
     142,    11,   102,    13,    94,    15,   124,    17,   118,    19,
     189,    21,    39,    33,     0,     0,     0,   144,     0,    96,
       0,     0,     0,    41,     0,    40,     0,     0,    34,    46,
       0,    67,     0,     0,     0,    72,    76,    78,    80,    82,
      84,   140,   168,   181,   200,     0,    66,     0,    50,    52,
      53,    54,    55,    56,    57,    64,    65,    58,    59,    60,
      61,    62,    63,   163,     0,   166,   161,   160,   158,   159,
       0,   152,   154,   155,   156,   157,   148,     0,   145,   146,
     114,   116,   112,   111,   109,   110,     0,   104,   106,   107,
     108,   100,     0,    97,    98,   137,     0,   135,   134,   132,
     133,   131,     0,   126,   128,   129,   130,   122,     0,   120,
     196,   198,   193,     0,   191,   194,   195,    38,     0,     0,
      31,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     0,
      49,     0,     0,     0,     0,     0,   151,     0,   143,     0,
       0,     0,     0,     0,   103,     0,    95,     0,     0,     0,
       0,     0,   125,     0,     0,   119,     0,     0,     0,   190,
      42,    35,     0,     0,     0,    69,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
     165,     0,     0,   153,     0,   147,     0,     0,     0,   105,
       0,    99,     0,   139,     0,   127,     0,   121,     0,     0,
     192,     0,     0,    68,    74,    75,    73,    77,    32,    79,
      81,    86,    86,   144,     0,   183,     0,   164,   167,   162,
     149,   115,     0,   113,   101,   138,   136,   123,   197,   199,
      36,     0,    92,    91,     0,    87,    88,    90,     0,     0,
     177,   179,   176,   174,   175,     0,   170,   172,   173,   187,
       0,   184,   185,   204,     0,   202,     0,    47,     0,     0,
      83,    85,   141,     0,     0,     0,   169,     0,   182,     0,
       0,     0,   201,   117,     0,    89,     0,     0,   171,     0,
     186,   215,   220,     0,   218,   214,   212,   213,     0,   206,
     208,   210,   211,   209,   203,    96,   178,   180,   188,     0,
       0,     0,     0,     0,   205,     0,     0,     0,   217,     0,
     207,    93,   216,     0,   219,   224,     0,   222,     0,     0,
     221,   233,     0,     0,     0,   238,     0,   226,   228,   229,
     230,   231,   232,   223,     0,     0,     0,     0,     0,     0,
     225,     0,   235,   236,   237,     0,   227,   234,   239
  };

  const short
  D2Parser::yypgoto_[] =
  {
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,   -41,  -198,  -197,  -198,     3,  -198,  -198,  -198,
    -198,  -198,  -198,   -56,  -198,  -198,  -198,  -198,  -198,  -198,
      -2,    89,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,   -55,  -198,   -44,  -198,  -198,  -198,  -198,  -198,
      12,  -198,   -40,  -198,  -198,  -198,  -198,   -75,  -198,    75,
    -198,  -198,  -198,    80,    85,  -198,  -198,   -51,  -198,  -198,
    -198,  -198,  -198,    11,    78,  -198,  -198,  -198,    76,    83,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,    22,
    -198,    97,  -198,  -198,  -198,   100,   104,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,   -25,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,   -26,  -198,  -198,  -198,
     -21,    91,  -198,  -198,  -198,  -198,  -198,  -198,  -198,   -20,
    -198,  -198,   -53,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,   -67,  -198,  -198,   -86,  -198,  -198,  -198,  -198,  -198,
    -198,  -198
  };

  const short
  D2Parser::yydefgoto_[] =
  {
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    30,    31,    32,    53,   259,    67,    68,    33,
      52,    64,    65,    86,    35,    54,    70,   162,    37,    55,
      87,    88,    89,   164,    90,    91,    92,    93,   168,   256,
      94,   169,    95,   170,    96,   171,    97,   172,    98,   173,
     284,   285,   286,   287,   308,    45,    59,   132,   133,   134,
     195,    43,    58,   126,   127,   128,   192,   129,   190,   130,
     191,    49,    61,   148,   149,   203,    47,    60,   142,   143,
     144,   200,   145,   198,   146,    99,   174,    41,    57,   117,
     118,   119,   187,    39,    56,   110,   111,   112,   184,   113,
     181,   114,   115,   183,   100,   175,   295,   296,   297,   313,
     298,   314,   101,   176,   300,   301,   302,   317,    51,    62,
     153,   154,   155,   206,   156,   207,   102,   177,   304,   305,
     320,   338,   339,   340,   349,   341,   342,   352,   343,   350,
     366,   367,   368,   376,   377,   378,   384,   379,   380,   381,
     382,   388
  };

  const short
  D2Parser::yytable_[] =
  {
     107,   108,   123,   124,   138,   139,   152,   282,    34,   141,
      22,    63,   109,    23,   125,    24,   140,    25,    71,    72,
      73,    74,    75,   258,    36,    76,   179,    77,    78,    79,
      80,   180,    38,   204,    40,    81,   205,   135,   136,    82,
      42,    85,    83,   185,    44,    84,    77,    78,   186,   150,
     151,   120,   258,   137,    77,    78,   150,   151,    46,   193,
     321,    77,    78,   322,   194,    85,    26,    27,    28,    29,
     103,   104,   105,   331,   332,    48,   333,   334,    85,    50,
     106,    77,    78,    69,    85,    66,   120,   121,    77,    78,
     371,   116,    85,   372,   373,   374,   375,   254,   255,    85,
     122,   290,   291,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,   131,   147,   201,   208,   210,   211,    85,
     202,   209,   185,   193,   157,   158,    85,   270,   274,   107,
     108,   107,   108,   204,   160,   159,   323,   123,   124,   123,
     124,   109,   161,   109,   163,   138,   139,   138,   139,   125,
     141,   125,   141,   201,   188,   179,   309,   140,   277,   140,
     307,   310,   309,   315,   208,   353,   389,   311,   316,   348,
     354,   390,   369,   196,   165,   370,   166,   167,   178,   182,
     189,   197,   212,   199,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   229,
     230,   231,   232,   236,   237,   283,   283,   238,   292,   293,
     280,   242,   244,   243,   248,   249,   251,   358,   263,   319,
     294,   252,   253,   257,    24,   261,   260,   262,   264,   265,
     266,   272,   392,   312,   267,   299,   303,   318,   324,   326,
     268,   269,   271,   327,   361,   345,   351,   356,   357,   359,
     281,   363,   279,   283,   273,   365,   385,   386,   387,   292,
     293,   152,   391,   275,   335,   336,   395,   276,   228,   325,
     355,   294,   241,   278,   288,   240,   337,   346,   239,   246,
     347,   362,   247,   306,   245,   289,   235,   234,   364,   233,
     328,   393,   394,   330,   397,   398,   329,   335,   336,   250,
     360,   344,   383,   396,     0,     0,     0,     0,     0,   337
  };

  const short
  D2Parser::yycheck_[] =
  {
      56,    56,    58,    58,    60,    60,    62,    24,     7,    60,
       0,    52,    56,     5,    58,     7,    60,     9,    11,    12,
      13,    14,    15,   220,     7,    18,     3,    20,    21,    22,
      23,     8,     7,     3,     5,    28,     6,    11,    12,    32,
       7,    58,    35,     3,     5,    38,    20,    21,     8,    36,
      37,    25,   249,    27,    20,    21,    36,    37,     7,     3,
       3,    20,    21,     6,     8,    58,    58,    59,    60,    61,
      29,    30,    31,    39,    40,     5,    42,    43,    58,     7,
      39,    20,    21,    10,    58,    58,    25,    26,    20,    21,
      41,     7,    58,    44,    45,    46,    47,    16,    17,    58,
      39,    33,    34,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     7,     7,     3,     3,   158,   159,    58,
       8,     8,     3,     3,     6,     3,    58,     8,     8,   185,
     185,   187,   187,     3,     8,     4,     6,   193,   193,   195,
     195,   185,     3,   187,     8,   201,   201,   203,   203,   193,
     201,   195,   203,     3,     6,     3,     3,   201,     8,   203,
       8,     8,     3,     3,     3,     3,     3,     8,     8,     8,
       8,     8,     3,     6,     4,     6,     4,     4,     4,     4,
       3,     3,    58,     4,     4,     4,    59,    59,    59,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
      59,     4,     4,     4,     4,   261,   262,     4,   264,   264,
     251,     4,     4,    59,     4,     4,     4,    59,     5,     3,
     264,     7,    58,    19,     7,     7,    58,     7,     7,     5,
       5,     5,    61,     6,    58,     7,     7,     6,     4,     4,
      58,    58,    58,     4,     6,     5,     4,     4,     4,     4,
     252,     5,   249,   309,    58,     7,     4,     4,     4,   315,
     315,   317,     4,    58,   320,   320,     4,    58,   179,   309,
     345,   315,   197,    58,   262,   195,   320,    58,   193,   203,
      58,    58,   204,   272,   201,   263,   189,   187,    58,   185,
     315,    59,    59,   319,    58,    58,   317,   353,   353,   208,
     353,   321,   369,   389,    -1,    -1,    -1,    -1,    -1,   353
  };

  const unsigned char
  D2Parser::yystos_[] =
  {
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     5,     7,     9,    58,    59,    60,    61,
      74,    75,    76,    81,     7,    86,     7,    90,     7,   155,
       5,   149,     7,   123,     5,   117,     7,   138,     5,   133,
       7,   180,    82,    77,    87,    91,   156,   150,   124,   118,
     139,   134,   181,    74,    83,    84,    58,    79,    80,    10,
      88,    11,    12,    13,    14,    15,    18,    20,    21,    22,
      23,    28,    32,    35,    38,    58,    85,    92,    93,    94,
      96,    97,    98,    99,   102,   104,   106,   108,   110,   147,
     166,   174,   188,    29,    30,    31,    39,    85,   104,   106,
     157,   158,   159,   161,   163,   164,     7,   151,   152,   153,
      25,    26,    39,    85,   104,   106,   125,   126,   127,   129,
     131,     7,   119,   120,   121,    11,    12,    27,    85,   104,
     106,   129,   140,   141,   142,   144,   146,     7,   135,   136,
      36,    37,    85,   182,   183,   184,   186,     6,     3,     4,
       8,     3,    89,     8,    95,     4,     4,     4,   100,   103,
     105,   107,   109,   111,   148,   167,   175,   189,     4,     3,
       8,   162,     4,   165,   160,     3,     8,   154,     6,     3,
     130,   132,   128,     3,     8,   122,     6,     3,   145,     4,
     143,     3,     8,   137,     3,     6,   185,   187,     3,     8,
      74,    74,    58,     4,     4,    59,    59,    59,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,    93,     4,
      59,     4,     4,   158,   157,   153,     4,     4,     4,   126,
     125,   121,     4,    59,     4,   141,   140,   136,     4,     4,
     183,     4,     7,    58,    16,    17,   101,    19,    76,    78,
      58,     7,     7,     5,     7,     5,     5,    58,    58,    58,
       8,    58,     5,    58,     8,    58,    58,     8,    58,    78,
      74,    92,    24,    85,   112,   113,   114,   115,   112,   151,
      33,    34,    85,   104,   106,   168,   169,   170,   172,     7,
     176,   177,   178,     7,   190,   191,   135,     8,   116,     3,
       8,     8,     6,   171,   173,     3,     8,   179,     6,     3,
     192,     3,     6,     6,     4,   114,     4,     4,   169,   182,
     178,    39,    40,    42,    43,    85,   104,   106,   193,   194,
     195,   197,   198,   200,   191,     5,    58,    58,     8,   196,
     201,     4,   199,     3,     8,   119,     4,     4,    59,     4,
     194,     6,    58,     5,    58,     7,   202,   203,   204,     3,
       6,    41,    44,    45,    46,    47,   205,   206,   207,   209,
     210,   211,   212,   203,   208,     4,     4,     4,   213,     3,
       8,     4,    61,    59,    59,     4,   206,    58,    58
  };

  const unsigned char
  D2Parser::yyr1_[] =
  {
       0,    62,    64,    63,    65,    63,    66,    63,    67,    63,
      68,    63,    69,    63,    70,    63,    71,    63,    72,    63,
      73,    63,    74,    74,    74,    74,    74,    74,    74,    75,
      77,    76,    78,    79,    79,    80,    80,    82,    81,    83,
      83,    84,    84,    85,    87,    86,    89,    88,    91,    90,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    95,    94,    96,
      97,    98,   100,    99,   101,   101,   103,   102,   105,   104,
     107,   106,   109,   108,   111,   110,   112,   112,   113,   113,
     114,   114,   116,   115,   118,   117,   119,   119,   120,   120,
     122,   121,   124,   123,   125,   125,   126,   126,   126,   126,
     126,   126,   128,   127,   130,   129,   132,   131,   134,   133,
     135,   135,   137,   136,   139,   138,   140,   140,   141,   141,
     141,   141,   141,   141,   141,   143,   142,   145,   144,   146,
     148,   147,   150,   149,   151,   151,   152,   152,   154,   153,
     156,   155,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   160,   159,   162,   161,   163,   165,   164,   167,   166,
     168,   168,   169,   169,   169,   169,   169,   171,   170,   173,
     172,   175,   174,   176,   176,   177,   177,   179,   178,   181,
     180,   182,   182,   182,   183,   183,   185,   184,   187,   186,
     189,   188,   190,   190,   192,   191,   193,   193,   194,   194,
     194,   194,   194,   194,   194,   196,   195,   197,   199,   198,
     201,   200,   202,   202,   204,   203,   205,   205,   206,   206,
     206,   206,   206,   208,   207,   209,   210,   211,   213,   212
  };

  const signed char
  D2Parser::yyr2_[] =
  {
       0,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     1,     0,     1,     3,     5,     0,     4,     0,
       1,     1,     3,     2,     0,     4,     0,     6,     0,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     3,
       3,     3,     0,     4,     1,     1,     0,     4,     0,     4,
       0,     4,     0,     6,     0,     6,     0,     1,     1,     3,
       1,     1,     0,     6,     0,     4,     0,     1,     1,     3,
       0,     4,     0,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     0,     6,     0,     4,
       1,     3,     0,     4,     0,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     0,     4,     3,
       0,     6,     0,     4,     0,     1,     1,     3,     0,     4,
       0,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     4,     3,     0,     4,     0,     6,
       1,     3,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     6,     0,     1,     1,     3,     0,     4,     0,
       4,     1,     3,     1,     1,     1,     0,     4,     0,     4,
       0,     6,     1,     3,     0,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     3,     0,     4,
       0,     6,     1,     3,     0,     4,     1,     3,     1,     1,
       1,     1,     1,     0,     4,     3,     3,     3,     0,     4
  };


#if D2_PARSER_DEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const D2Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\",\"", "\":\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"null\"", "\"DhcpDdns\"",
  "\"ip-address\"", "\"port\"", "\"dns-server-timeout\"",
  "\"dns_server_max-attempts\"", "\"ncr-protocol\"", "\"UDP\"", "\"TCP\"",
  "\"ncr-format\"", "\"JSON\"", "\"user-context\"", "\"comment\"",
  "\"forward-ddns\"", "\"reverse-ddns\"", "\"ddns-domains\"",
  "\"key-name\"", "\"dns-servers\"", "\"hostname\"", "\"tsig-keys\"",
  "\"algorithm\"", "\"digest-bits\"", "\"secret\"", "\"control-socket\"",
  "\"socket-type\"", "\"socket-name\"", "\"hooks-libraries\"",
  "\"library\"", "\"parameters\"", "\"loggers\"", "\"name\"",
  "\"output_options\"", "\"output\"", "\"debuglevel\"", "\"severity\"",
  "\"flush\"", "\"maxsize\"", "\"maxver\"", "\"pattern\"", "TOPLEVEL_JSON",
  "TOPLEVEL_DHCPDDNS", "SUB_DHCPDDNS", "SUB_TSIG_KEY", "SUB_TSIG_KEYS",
  "SUB_DDNS_DOMAIN", "SUB_DDNS_DOMAINS", "SUB_DNS_SERVER",
  "SUB_DNS_SERVERS", "SUB_HOOKS_LIBRARY", "\"constant string\"",
  "\"integer\"", "\"floating point\"", "\"boolean\"", "$accept", "start",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "value", "sub_json", "map2", "$@11", "map_value", "map_content",
  "not_empty_map", "list_generic", "$@12", "list_content",
  "not_empty_list", "unknown_map_entry", "syntax_map", "$@13",
  "global_object", "$@14", "sub_dhcpddns", "$@15", "dhcpddns_params",
  "dhcpddns_param", "ip_address", "$@16", "port", "dns_server_timeout",
  "dns_server_max_attempts", "ncr_protocol", "$@17", "ncr_protocol_value",
  "ncr_format", "$@18", "user_context", "$@19", "comment", "$@20",
  "forward_ddns", "$@21", "reverse_ddns", "$@22", "ddns_mgr_params",
  "not_empty_ddns_mgr_params", "ddns_mgr_param", "ddns_domains", "$@23",
  "sub_ddns_domains", "$@24", "ddns_domain_list",
  "not_empty_ddns_domain_list", "ddns_domain", "$@25", "sub_ddns_domain",
  "$@26", "ddns_domain_params", "ddns_domain_param", "ddns_domain_name",
  "$@27", "ddns_key_name", "$@28", "dns_servers", "$@29",
  "sub_dns_servers", "$@30", "dns_server_list", "dns_server", "$@31",
  "sub_dns_server", "$@32", "dns_server_params", "dns_server_param",
  "dns_server_hostname", "$@33", "dns_server_ip_address", "$@34",
  "dns_server_port", "tsig_keys", "$@35", "sub_tsig_keys", "$@36",
  "tsig_keys_list", "not_empty_tsig_keys_list", "tsig_key", "$@37",
  "sub_tsig_key", "$@38", "tsig_key_params", "tsig_key_param",
  "tsig_key_name", "$@39", "tsig_key_algorithm", "$@40",
  "tsig_key_digest_bits", "tsig_key_secret", "$@41", "control_socket",
  "$@42", "control_socket_params", "control_socket_param",
  "control_socket_type", "$@43", "control_socket_name", "$@44",
  "hooks_libraries", "$@45", "hooks_libraries_list",
  "not_empty_hooks_libraries_list", "hooks_library", "$@46",
  "sub_hooks_library", "$@47", "hooks_params", "hooks_param", "library",
  "$@48", "parameters", "$@49", "loggers", "$@50", "loggers_entries",
  "logger_entry", "$@51", "logger_params", "logger_param", "name", "$@52",
  "debuglevel", "severity", "$@53", "output_options_list", "$@54",
  "output_options_list_content", "output_entry", "$@55",
  "output_params_list", "output_params", "output", "$@56", "flush",
  "maxsize", "maxver", "pattern", "$@57", YY_NULLPTR
  };
#endif


#if D2_PARSER_DEBUG
  const short
  D2Parser::yyrline_[] =
  {
       0,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   143,   144,   145,   146,   147,   148,   149,   152,
     157,   157,   168,   171,   172,   175,   180,   188,   188,   195,
     196,   199,   203,   214,   223,   223,   236,   236,   247,   247,
     255,   256,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   277,   277,   286,
     295,   305,   315,   315,   324,   325,   328,   328,   337,   337,
     362,   362,   389,   389,   400,   400,   411,   412,   415,   416,
     419,   420,   425,   425,   436,   436,   443,   444,   447,   448,
     451,   451,   459,   459,   466,   467,   470,   471,   472,   473,
     474,   475,   479,   479,   492,   492,   505,   505,   516,   516,
     523,   524,   527,   527,   535,   535,   542,   543,   546,   547,
     548,   549,   550,   551,   552,   555,   555,   568,   568,   577,
     592,   592,   603,   603,   610,   611,   614,   615,   618,   618,
     626,   626,   635,   636,   639,   640,   641,   642,   643,   644,
     645,   648,   648,   661,   661,   673,   682,   682,   699,   699,
     710,   711,   714,   715,   716,   717,   718,   721,   721,   730,
     730,   741,   741,   752,   753,   756,   757,   760,   760,   770,
     770,   780,   781,   782,   785,   786,   789,   789,   798,   798,
     808,   808,   821,   822,   826,   826,   834,   835,   838,   839,
     840,   841,   842,   843,   844,   847,   847,   856,   862,   862,
     871,   871,   882,   883,   886,   886,   894,   895,   898,   899,
     900,   901,   902,   905,   905,   914,   920,   926,   932,   932
  };

  void
  D2Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  D2Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // D2_PARSER_DEBUG


#line 14 "d2_parser.yy"
} } // isc::d2
#line 2713 "d2_parser.cc"

#line 941 "d2_parser.yy"


void
isc::d2::D2Parser::error(const location_type& loc,
                              const std::string& what)
{
    ctx.error(loc, what);
}
