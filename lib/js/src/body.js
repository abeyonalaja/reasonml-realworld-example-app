// Generated by BUCKLESCRIPT VERSION 1.8.2, PLEASE EDIT WITH CARE
'use strict';

var React       = require("react");
var Header      = require("./header.js");
var ReasonReact = require("reason-react/lib/js/src/reasonReact.js");

var component = ReasonReact.statelessComponent("Body");

function show(prim) {
  return prim;
}

function make() {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, ReasonReact.element(/* None */0, /* None */0, Header.make(/* array */[])));
    });
  return newrecord;
}

exports.component = component;
exports.show      = show;
exports.make      = make;
/* component Not a pure module */