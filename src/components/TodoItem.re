type state = {
    description: string,
    completed: bool
};

type action =
  | Click;

let component = ReasonReact.reducerComponent("todoItem");

let str = ReasonReact.string;

let make = (~description, ~showCompleted, _children) => {
    ...component,

    initialState: () => {description, completed: false},

    reducer: (action, state) => 
        switch(action){
            | Click => ReasonReact.Update({...state, completed: !state.completed}) 
        },
    render: ({state, send}) => {
        (!showCompleted && state.completed) ? str("") :
        <div className="contentRow" onClick=((_) => send(Click))>
            <CheckBox color="black" checked=state.completed />
            <HorizontalSpacer size="50" />
            <div className="todoItem">{str(state.description)}</div>
        </div> /*</contentRow>*/
    }
};