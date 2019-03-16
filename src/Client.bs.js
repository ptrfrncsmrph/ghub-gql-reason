// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var ApolloLinks = require("reason-apollo/src/ApolloLinks.bs.js");
var ApolloLink = require("apollo-link");
var ReasonApollo = require("reason-apollo/src/ReasonApollo.bs.js");
var ApolloInMemoryCache = require("reason-apollo/src/ApolloInMemoryCache.bs.js");

var inMemoryCache = ApolloInMemoryCache.createInMemoryCache(undefined, undefined, /* () */0);

var accessToken = "29b20cc5d89037171fab000ab4c5374e08372055";

function contextHandler(param) {
  return {
          headers: {
            authorization: "Bearer " + (String(accessToken) + "")
          }
        };
}

var authLink = ApolloLinks.createContextLink(contextHandler);

var httpLink = ApolloLinks.createHttpLink("https://api.github.com/graphql", undefined, undefined, undefined, undefined, undefined, /* () */0);

var instance = ReasonApollo.createApolloClient(ApolloLink.from(/* array */[
          authLink,
          httpLink
        ]), inMemoryCache, undefined, undefined, undefined, undefined, /* () */0);

exports.inMemoryCache = inMemoryCache;
exports.accessToken = accessToken;
exports.contextHandler = contextHandler;
exports.authLink = authLink;
exports.httpLink = httpLink;
exports.instance = instance;
/* inMemoryCache Not a pure module */
