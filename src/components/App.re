module Commits = [%graphql
  {|
  query Commits {
    user(login: "ptrfrncsmrph") {
      name
      contributionsCollection {
        commitContributionsByRepository {
          repository {
            name
          }
          contributions(first: 100) {
            pageInfo {
              hasNextPage
            }
            nodes {
              occurredAt
            }
          }
        }
      }
    }
  }
  |}
];

module CommitsQuery = ReasonApollo.CreateQuery(Commits);

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => {
    let commitsQuery = Commits.make();
    <div>
      <h1> {"githubub" |> ReasonReact.string} </h1>
      <CommitsQuery variables=commitsQuery##variables>
        ...{({result}) =>
          switch (result) {
          | Loading => <div> {"Loading..." |> ReasonReact.string} </div>
          | Error(error) =>
            <div> {error##message |> ReasonReact.string} </div>
          | Data(response) =>
            switch (response##user) {
            | None => <div> {"No user was found" |> ReasonReact.string} </div>
            | Some(user) =>
              switch (user##name) {
              | None =>
                <div>
                  {"No name was associated with this user"
                   |> ReasonReact.string}
                </div>
              | Some(name) => <div> {name |> ReasonReact.string} </div>
              }
            }
          }
        }
      </CommitsQuery>
    </div>;
  },
};