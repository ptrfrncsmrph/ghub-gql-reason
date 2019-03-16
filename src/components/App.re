module Commits = [%graphql
  {|
  query Commits {
    user(login: "ptrfrncsmrph") {
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
          | Data(data) => <pre> {data |> ReasonReact.string} </pre>
          }
        }
      </CommitsQuery>
    </div>;
  },
};