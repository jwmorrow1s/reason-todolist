// Generated by BUCKLESCRIPT VERSION 4.0.14, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var TodoItem$ReactTemplate = require("./TodoItem.bs.js");

var component = ReasonReact.statelessComponent("todos");

function make(todos, toParent, showCompleted, param) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              return $$Array.of_list(List.map((function (todo) {
                                return React.createElement("div", {
                                            key: String(todo[/* id */2]),
                                            onClick: (function (param) {
                                                return Curry._1(toParent, /* ToggleComplete */Block.__(2, [todo[/* id */2]]));
                                              })
                                          }, ReasonReact.element(undefined, undefined, TodoItem$ReactTemplate.make(todo, showCompleted, /* array */[])));
                              }), todos));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
