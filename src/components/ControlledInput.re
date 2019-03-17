// [%bs.raw  {| const {controlledInput} = require(":) |}]

[@bs.module]
external controlledInput: ReasonReact.reactClass =
  "./../../output/ControlledInput";

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=controlledInput,
    ~props=(),
    children,
  );