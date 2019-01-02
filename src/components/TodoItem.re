let component = ReasonReact.statelessComponent("todoItem");

let str = ReasonReact.string;

let make = (~description, ~showCompleted, ~completed, _children) => {
    ...component,

    render: _ => {
        (!showCompleted && completed) ? str("") :
        <div className="contentRow">
            <CheckBox color="black" checked=completed />
            <HorizontalSpacer size="50" />
            <div className="todoItem">{str(description)}</div>
        </div> /*</contentRow>*/
    }
};