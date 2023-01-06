  const renameRule = () => {
    <React.Fragment>
      <Row>
        <Col xs={8} sm={8} md={8} lg={8} xl={8}>
          'Rename Labels'
        </Col>
        <Col xs={16} sm={16} md={16} lg={16} xl={16}>
          <Switch key={switchKey} defaultChecked={enableRenameLabels} onChange={enableRenameLabelsChange} />
        </Col>
      </Row>

    </React.Fragment>
  }





  const enableRenameLabelsChange = (enren) => {
    // setEnableRenameLabels(enren);
    

  }






