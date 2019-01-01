// Generated by BUCKLESCRIPT VERSION 4.0.14, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("checkbox");

function str(prim) {
  return prim;
}

function checkbox(color, checked) {
  return React.createElement("div", {
              className: "Checkbox",
              style: {
                backgroundColor: "white",
                border: "2px solid " + color,
                color: color,
                fontFamily: "sans-serif",
                fontSize: "2vh",
                height: "2vh",
                marginTop: "3px",
                textAlign: "center",
                width: "2vw"
              }
            }, checked ? "X" : "");
}

function make(color, checked, param) {
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
          /* render */(function (_self) {
              return checkbox(color, checked);
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.str = str;
exports.checkbox = checkbox;
exports.make = make;
/* component Not a pure module */