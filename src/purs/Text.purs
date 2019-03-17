module Text where

import Prelude

import React.Basic (Component, JSX, createComponent, makeStateless)
import React.Basic.DOM as R

component :: Component Unit
component = createComponent "Text"

text :: Unit -> JSX
text = makeStateless component \_ ->
  R.text "HELLO"