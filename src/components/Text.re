[@bs.module] external text: Js.t('a) = "./../../output/Text";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass=text##text, ~props=(), children);